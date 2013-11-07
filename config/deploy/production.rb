role :app, "10.179.105.161", "10.179.109.96", "10.179.111.84", "10.179.38.7", primary: true
#role :db, "db.dosomething.org"
set :deploy_to, "/var/www/v2"
set :gateway, 'admin.dosomething.org'
set :port, '38383'
