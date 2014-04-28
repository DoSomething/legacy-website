set :deploy_to, "/var/www/international.dosomething.org"

role :app, %w{dosomething@dosomething@deploy.international.dosomething.org}

server 'deploy.international.dosomething.org', user: 'dosomething', roles: %w{app}

namespace :deploy do

  task :shared_links do
    on roles(:app) do |host|
      execute "rm -rf #{release_path}/html/sites"
      execute "sudo ln -s #{shared_path}/sites #{release_path}/html/sites"
    end
  end

  after :build, 'deploy:shared_links'

end
