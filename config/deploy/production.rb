set :deploy_to, "/var/www/beta.dosomething.org"

role :app, %w{dosomething@10.241.0.26}

server '10.241.0.26', user: 'dosomething', roles: %w{app}

namespace :deploy do

  task :shared_links do
    on roles(:app) do |host|
      execute "cd '#{release_path}/html/sites/default'; rm -rf files 2> /dev/null; ln -s #{shared_path}/files files"
      execute "ln -s #{shared_path}/settings.production.php #{release_path}/html/sites/default/settings.production.php"
    end
  end

  after :build, 'deploy:shared_links'

end
