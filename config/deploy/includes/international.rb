set :deploy_to, "/var/www/international.dosomething.org"

case ENV['stage']
when production
  role :app, %w{dosomething@dosomething@deploy.international.dosomething.org}
  server 'deploy.international.dosomething.org', user: 'dosomething', roles: %w{app}

when qa
  role :app, %w{dosomething@10.241.0.33}
  server '10.241.0.33', user: 'dosomething', roles: %w{app}
end