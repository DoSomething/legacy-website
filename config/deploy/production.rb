role :app, *@config['production']['servers'], primary: true
#role :db, "db.dosomething.org"
set :gateway, @config['production']['gateway']
set :port, '38383'
set :branch, @config['production']['branch']
set :deploy_to, @config['production']['deploy_to']
