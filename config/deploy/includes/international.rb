set :deploy_to, "/var/www/international.dosomething.org"

case ENV['stage']
when 'production'
  role :app, %w{dosomething@deploy.international.dosomething.org}
  server 'deploy.international.dosomething.org', user: 'dosomething', roles: %w{app}

when 'qa'
  role :app, %w{dosomething@intl-qa}
  server 'intl-qa', user: 'dosomething', roles: %w{app}
end