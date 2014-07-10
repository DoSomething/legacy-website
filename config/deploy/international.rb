set :deploy_to, "/var/www/international.dosomething.org"

set :deploy_env, "intl"

sites = %{botswana canada congo ghana kenya indonesia training uk}

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

  desc "Run ds build tasks for international"
  task :build do
    on roles(:app) do |host|
      execute "cd '#{release_path}'; #{release_path}/bin/ds build --intl"
      execute "cd '#{release_path}/lib/themes/dosomething/paraneue_dosomething'; grunt prod"
      sites.each do |site|
        execute "cd '#{release_path}/html/sites/#{site}'; drush vset --yes ds_version " + ENV['branch']
        execute "cd '#{release_path}/html/sites/#{site}'; echo " + ENV['branch'] + " > VERSION"
      end
    end
  end

  after :updated, 'deploy:build'
  after :build, 'deploy:shared_links'

end
