# Basic configuration for the production environment.  Please see
# https://github.com/DoSomething/dosomething/wiki/Setting-up-deploy-vars
# for more details.

role :app, *@config['production']['servers'], primary: true
set :gateway, @config['production']['gateway']
set :port, @config['production']['port']
set :branch, @config['production']['branch']
set :deploy_to, @config['production']['deploy_to']
