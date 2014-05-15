# config valid only for Capistrano 3.1
lock '3.1.0'

set :application, 'beta.dosomething.org'
set :repo_url, 'git@github.com:DoSomething/dosomething.git'

set :branch, "dev"
if ENV['branch']
    set :branch, ENV['branch'] || 'dev'
end

set :ssh_options, { :forward_agent => true }

namespace :deploy do

  desc "Run ds build tasks"
  task :build do
    on roles(:app) do |host|
      execute "cd '#{release_path}'; #{release_path}/bin/ds build"
      execute "cd '#{release_path}/lib/themes/dosomething/paraneue_dosomething'; grunt prod"
      execute "cd '#{release_path}/html'; drush vset --yes ds_version " + ENV['branch']
      execute "cd '#{release_path}/html'; echo " + ENV['branch'] + " > VERSION"
    end
  end

  after :updated, 'deploy:build'

end
