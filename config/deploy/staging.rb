set :deploy_to, "/var/www/beta.dosomething.org"

set :deploy_env, "stage"

role :app, %w{dosomething@staging}

server 'staging', user: 'dosomething', roles: %w{app}

