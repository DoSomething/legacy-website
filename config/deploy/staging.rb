set :deploy_to, "/var/www/beta.dosomething.org"

role :app, %w{dosomething@staging}

server 'staging', user: 'dosomething', roles: %w{app}

