set :deploy_to, "/var/www/beta.dosomething.org"

role :app, %w{dosomething@beta.staging.test}

server 'beta.staging.test', user: 'dosomething', roles: %w{app}

