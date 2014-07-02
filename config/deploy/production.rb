set :deploy_to, "/var/www/beta.dosomething.org"

set :deploy_env, "production"

role :app, %w{dosomething@beta-web1}

server 'beta-web1', user: 'dosomething', roles: %w{app}
