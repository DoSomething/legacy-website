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

namespace :build do
  task :pull do
    run "#{try_sudo} su - jenkins sh -c \"cd #{build_path} && git stash && git pull --rebase && git stash pop\""
  end
  task :clear_cache do
    run "#{try_sudo} su - jenkins sh -c \"cd #{build_path} && vagrant ssh --command 'cd #{source_path} && drush cc all'\""
  end
end

after 'build:pull', 'build:clear_cache'

