server "192.168.1.169", :app, :web, :db, primary: true
set :deploy_to, "/var/www/v2/qa"
set :user, @config['qa']['user']
set :password, @config['qa']['password']

set :build_path, "/home/jenkins/dosomething-vagrant"
set :source_path, "/vagrant/html"
set :use_sudo, true 

namespace :build do
  task :pull do
    run "#{try_sudo} su - jenkins sh -c \"cd #{build_path} && git stash && git pull --rebase && git stash pop\""
  end
  task :clear_cache do
    run "#{try_sudo} su - jenkins sh -c \"cd #{build_path} && vagrant ssh --command 'cd #{source_path} && drush cc all'\""
  end
end

after 'build:pull', 'build:clear_cache'

