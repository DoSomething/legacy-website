# config valid only for Capistrano 3.1
lock '3.1.0'

set :application, 'beta.dosomething.org'
set :repo_url, 'git@github.com:DoSomething/dosomething.git'

# Default branch is :master
# ask :branch, proc { `git rev-parse --abbrev-ref HEAD`.chomp }

set :branch, "dev"

# Default deploy_to directory is /var/www/my_app
# set :deploy_to, '/var/www/my_app'

# Default value for :scm is :git
set :scm, :git

# Default value for :format is :pretty
set :format, :pretty

# Default value for :log_level is :debug
set :log_level, :debug

set :ssh_options, { :forward_agent => true }
# Default value for :pty is false
# set :pty, true

# Default value for :linked_files is []
# set :linked_files, %w{config/database.yml}

# Default value for linked_dirs is []
# set :linked_dirs, %w{bin log tmp/pids tmp/cache tmp/sockets vendor/bundle public/system}

# Default value for default_env is {}
# set :default_env, { path: "/opt/ruby/bin:$PATH" }

# Default value for keep_releases is 5
# set :keep_releases, 5

namespace :deploy do

  desc 'Restart application'
  task :restart do
    on roles(:app), in: :sequence, wait: 5 do
      # Your restart mechanism here, for example:
      # execute :touch, release_path.join('tmp/restart.txt')
    end
  end

  after :publishing, :restart

  after :restart, :clear_cache do
    on roles(:web), in: :groups, limit: 3, wait: 10 do
      # Here we can do anything such as:
      # within release_path do
      #   execute :rake, 'cache:clear'
      # end
    end
  end

  after :deploy, :drush_make do
    on roles(:app) do |host|
      execute "cd '#{release_path}'; ds build"
      execute "cd '#{release_path}/lib/themes/dosomething/paraneue_dosomething'; grunt prod"

      # The next two lines are temp until we get the "smart" settings reviewed and tested.
      execute "sudo rm -rf #{release_path}/html/sites/default/settings.php"
      execute "sudo rm -rf #{release_path}/html/sites/default/settings.local.php"

      # Also temporary.
      execute "ln -s #{release_path}/config/smart-settings.php #{release_path}/html/sites/default/settings.php"
    end
  end

end
