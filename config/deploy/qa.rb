# Basic configuration for the QA environment.  Please see
# https://github.com/DoSomething/dosomething/wiki/Deployments
# for more details.

role :app, *@config['qa']['servers'], primary: true
set :user, @config['qa']['user']
set :password, @config['qa']['password']
set :deploy_to, @config['qa']['deploy_to']
set :gateway, @config['qa']['gateway']
set :port, @config['qa']['port']

set :build_path, @config['qa']['deploy_to']
set :source_path, "/vagrant/html"
set :branch, @config['qa']['branch']
set :use_sudo, true 

# Runs a simple build on the QA server, so we don't have to deploy every time.
# This will run +git pull --rebase+, then +drush updb -y+ and +drush cc all+ within
# the vagrant instance on our QA server.
namespace :build do
  task :pull do
    # Changes to the +jenkins+ user, then stashes any changes, pulls down the latest
    # code, then pops the stash.
    run "#{try_sudo} su - jenkins sh -c \"cd #{build_path} && git stash && git pull --rebase && git stash pop\""
  end
  task :updb do
    # Updates the database by running +drush updb -y+.
    run "#{try_sudo} su - jenkins sh -c \"cd #{build_path} && vagrant ssh --command 'cd #{source_path} && drush updb -y'\""
  end
  task :clear_cache do
    # Clears the cache by running +drush cc all+.
    run "#{try_sudo} su - jenkins sh -c \"cd #{build_path} && vagrant ssh --command 'cd #{source_path} && drush cc all'\""
  end
end

after 'build:pull', 'build:updb'
after 'build:updb', 'build:clear_cache'

