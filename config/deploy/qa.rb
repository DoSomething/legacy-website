set :deploy_to, "/var/www/qa-beta"

role :app, %w{dosomething@blackangus.dosomething.org}

server 'blackangus.dosomething.org', user: 'dosomething', roles: %w{app}
