#
# Customized VCL file for serving up a Drupal site with multiple back-ends.
#
# For more information on this VCL, visit the Lullabot article:
# http://www.lullabot.com/articles/varnish-multiple-web-servers-drupal
#

# Define the internal network subnet.
# These are used below to allow internal access to certain files while not
# allowing access from the public internet.
acl internal {
  "localhost";
  "127.0.0.1";
}

# Define the list of backends (web servers).
# Port 80 Backend Servers
# backend webx { .host = "xx.xxx.xxx.xxx"; .probe = { .url = "/status.php"; .interval = 30s; .timeout = 10s; .window = 5;.threshold = 3; }}
backend web1 { .host = "127.0.0.1"; .port = "8888"; }

# Port 443 Backend Servers for SSL
#backend web1_ssl { .host = "192.10.0.1"; .port = "443"; .probe = { .url = "/status.php"; .interval = 5s; .timeout = 1 s; .window = 5;.threshold = 3; }}
#backend web2_ssl { .host = "192.10.0.2"; .port = "443"; .probe = { .url = "/status.php"; .interval = 5s; .timeout = 1 s; .window = 5;.threshold = 3; }}

# Define the director that determines how to distribute incoming requests.
director default_director round-robin {
  { .backend = web1; }
}

#director ssl_director round-robin {
#  { .backend = web1_ssl; }
#  { .backend = web2_ssl; }
#}

# Respond to incoming requests.
sub vcl_recv {
  if (req.http.host == "www.dosomething.com" || req.http.host == "dosomething.com" || req.http.host == "dosomething.org") {
    error 302;
  }
#  if (req.http.x-forwarded-for) {
#    set req.http.X-Forwarded-For = req.http.X-Forwarded-For ", " client.ip;
#  }
  if (req.http.X-Forwarded-For) {
    #set req.http.X-Forwarded-For = req.http.X-Forwarded-For;
  } else {
    set req.http.X-Forwarded-For = client.ip;
  }

  # Use anonymous, cached pages if all backends are down.
  if (!req.backend.healthy) {
    unset req.http.Cookie;
  }

  # Allow the backend to serve up stale content if it is responding slowly.
  set req.grace = 6h;

  # Do not cache these paths.
  if (req.url ~ "^/status\.php$" ||
      req.url ~ "^/update\.php$" ||
      req.url ~ "^/ooyala/ping$" ||
      req.url ~ "^/admin/build/features" ||
      req.url ~ "^/info/.*$" ||
      req.url ~ "^/flag/.*$" ||
      req.url ~ "^.*/ajax/.*$" ||
      req.url ~ "^.*/ahah/.*$") {
       return (pass);
  }

  # Pipe these paths directly to Apache for streaming.
  if (req.url ~ "^/admin/content/backup_migrate/export" || req.url ~ "^/batch") {
    return (pipe);
  }

  # Do not allow outside access to cron.php or install.php.
  if (req.url ~ "^/(cron|install)\.php$" && !client.ip ~ internal) {
    # Have Varnish throw the error directly.
    #error 404 "Page not found.";
    # Use a custom error page that you've defined in Drupal at the path "404".
     set req.url = "/404";
  }

  # Handle compression correctly. Different browsers send different
  # "Accept-Encoding" headers, even though they mostly all support the same
  # compression mechanisms. By consolidating these compression headers into
  # a consistent format, we can reduce the size of the cache and get more hits.=
  # @see: http:// varnish.projects.linpro.no/wiki/FAQ/Compression
  if (req.http.Accept-Encoding) {
    if (req.http.Accept-Encoding ~ "gzip") {
      # If the browser supports it, we'll use gzip.
      set req.http.Accept-Encoding = "gzip";
    }
    else if (req.http.Accept-Encoding ~ "deflate") {
      # Next, try deflate if it is supported.
      set req.http.Accept-Encoding = "deflate";
    }
    else {
      # Unknown algorithm. Remove it and send unencoded.
      unset req.http.Accept-Encoding;
    }
  }

  # Always cache the following file types for all users.
  if (req.url ~ "(?i)\.(png|gif|jpeg|jpg|ico|swf|css|js|html|htm)(\?[a-z0-9]+)?$") {
    unset req.http.Cookie;
  }

  # Remove all cookies that Drupal doesn't need to know about. ANY remaining
  # cookie will cause the request to pass-through to Apache. For the most part
  # we always set the NO_CACHE cookie after any POST request, disabling the
  # Varnish cache temporarily. The session cookie allows all authenticated users
  # to pass through as long as they're logged in.
  if (req.http.Cookie) {
    set req.http.Cookie = ";";
    set req.http.Cookie = regsuball(req.http.Cookie, "; +", ";");
    set req.http.Cookie = regsuball(req.http.Cookie, ";(S{1,2}ESS[a-z0-9]+|NO_CACHE|y\_oauth\_[A-Za-z0-9]+)=", "; \1=");
    set req.http.Cookie = regsuball(req.http.Cookie, ";[^ ][^;]*", "");
    set req.http.Cookie = regsuball(req.http.Cookie, "^[; ]+|[; ]+$", "");

    if (req.http.Cookie == "") {
      # If there are no remaining cookies, remove the cookie header. If there
      # aren't any cookie headers, Varnish's default behavior will be to cache
      # the page.
      unset req.http.Cookie;
    }
    else {
      # If there is any cookies left (a session or NO_CACHE cookie), do not
      # cache the page. Pass it on to Apache directly.
      return (pass);
    }
  }
}

# Routine used to determine the cache key if storing/retrieving a cached page.
sub vcl_hash {
  # Include cookie in cache hash.
  # This check is unnecessary because we already pass on all cookies.
  # if (req.http.Cookie) {
  #   set req.hash += req.http.Cookie;
  # }
  #
  set req.hash += req.url;
  if (req.http.host) {
    set req.hash += req.http.host;
  } else {
    set req.hash += server.ip;
  }
  if (req.http.X-Forwarded-Proto) {
    set req.hash += req.http.X-Forwarded-Proto;
  }
  return (hash);
}

# Code determining what to do when serving items from the Apache servers.
sub vcl_fetch {
  # CJ - 3/26/2012 - Add support to pipe requests through to Apache for imagecache
  if (beresp.status >= 400 && req.backend == fileserver && req.restarts == 0) {
    restart;
  }
  # Don't allow static files to set cookies.
  if (req.url ~ "(?i)\.(png|gif|jpeg|jpg|ico|swf|css|js|html|htm|woff)(\?[a-z0-9]+)?$") {
    # beresp == Back-end response from the web server.
    unset beresp.http.set-cookie;
  }

  # Allow items to be stale if needed.
  set beresp.grace = 6h;
}

# In the event of an error, show friendlier messages.
sub vcl_error {
  if (obj.status == 302)
  {
    set obj.http.Location = "http://www.dosomething.org" req.url;
    set obj.status = 302;
  }
  # CJ - 3/26/2012 - Add support for bypassing nginx on 404s
  if (req.restarts == 0 && req.backend == fileserver) {
    restart;
  }
  # Redirect to some other URL in the case of a homepage failure.
  #if (req.url ~ "^/?$") {
  #  set obj.status = 302;
  #  set obj.http.Location = "http://backup.example.com/";
  #}

  # Otherwise redirect to the homepage, which will likely be in the cache.
  set obj.http.Content-Type = "text/html; charset=utf-8";
  synthetic {"
<html>
<head>
  <title>Page Unavailable</title>
  <style>
    body { background: #303030; text-align: center; color: white; }
    #page { border: 1px solid #CCC; width: 500px; margin: 100px auto 0; padding: 30px; background: #323232; }
    a, a:link, a:visited { color: #CCC; }
    .error { color: #222; }
  </style>
</head>
<body onload="setTimeout(function() { window.location = '/' }, 5000)">
  <div id="page">
    <h1 class="title">Page Unavailable</h1>
    <p>The page you requested is temporarily unavailable.</p>
    <p>We're redirecting you to the <a href="/">homepage</a> in 5 seconds.</p>
    <div class="error">(Error "} obj.status " " obj.response {")</div>
  </div>
</body>
</html>
"};
  return (deliver);
}

sub vcl_deliver {
  if (obj.hits > 0) {
    set resp.http.X-Cache = "HIT";
  } else {
    set resp.http.X-Cache = "MISS";
  }
}
