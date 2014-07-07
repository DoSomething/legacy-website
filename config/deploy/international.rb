set :deploy_to, "/var/www/international.dosomething.org"

case ENV['STAGE']
when 'production'
  role :app, %w{dosomething@deploy.international.dosomething.org}
  server 'deploy.international.dosomething.org', user: 'dosomething', roles: %w{app}

when 'qa'
  role :app, %w{dosomething@intl-qa}
  server 'intl-qa', user: 'dosomething', roles: %w{app}
end

namespace :deploy do

  task :shared_links do
    on roles(:app) do |host|
      execute "rm -rf #{release_path}/html/sites"
      execute "sudo ln -s #{shared_path}/sites #{release_path}/html/sites"
    end
  end

  after :build, 'deploy:shared_links'

end
