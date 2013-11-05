server "192.168.1.169", :app, :web, :db, primary: true
set :deploy_to, "/var/www/v2/qa"
set :user, @config['qa']['user']
set :password, @config['qa']['password']

