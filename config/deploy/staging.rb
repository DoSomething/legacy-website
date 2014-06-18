set :deploy_to, "/var/www/beta.dosomething.org"

role :app, %w{dosomething@10.241.0.22}

server '10.241.0.22', user: 'dosomething', roles: %w{app}

