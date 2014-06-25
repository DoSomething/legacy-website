set :deploy_to, "/var/www/beta.dosomething.org"

role :app, %w{dosomething@beta.prod.test}

server 'beta.prod.test', user: 'dosomething', roles: %w{app}
