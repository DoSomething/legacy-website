set :deploy_to, "/var/www/qa-beta"

set :deploy_env, "qa"

role :app, %w{dosomething@blackangus.dosomething.org}

server 'blackangus.dosomething.org', user: 'dosomething', roles: %w{app}
