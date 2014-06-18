set :deploy_to, "/var/www/beta.dosomething.org"

role :app, %w{dosomething@10.241.0.26}

server '10.241.0.26', user: 'dosomething', roles: %w{app}
