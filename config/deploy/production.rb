set :deploy_to, "/var/www/beta.dosomething.org"

role :app, %w{dosomething@beta-web1}

server 'beta-web1', user: 'dosomething', roles: %w{app}
