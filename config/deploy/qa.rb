server "192.168.1.169", :app, :web, :db, primary: true
set :deploy_to, "/var/www/v2/qa"
set :user, @config['qa']['user']
set :password, @config['qa']['password']

set :build_path, "/home/jenkins/dosomething-vagrant"
set :use_sudo, true 

namespace :build do
  task :pull do
    run "cd #{build_path} && #{try_sudo} chown -R dosomething:dosomething * && git stash && git pull --rebase && git stash pop && #{try_sudo} chown -R jenkins:jenkins *"
  end
  task :clear_cache do
    run "#{try_sudo} su - jenkins sh -c \"cd ~/dosomething-vagrant && vagrant ssh --command 'drush cc all'\""
  end
end

after 'build:pull', 'build:clear_cache'

