set :deploy_to, "/var/www/international.dosomething.org"

set :deploy_env, "intl"

sites = %w{botswana canada congo ghana kenya indonesia training uk}

case ENV['STAGE']
when 'production'
  role :app, %w{dosomething@deploy.international.dosomething.org}
  server 'deploy.international.dosomething.org', user: 'dosomething', roles: %w{app}

when 'qa'
  role :app, %w{dosomething@intl-qa}
  server 'intl-qa', user: 'dosomething', roles: %w{app}
end

namespace :deploy do

  task :shared_international_links do
    on roles(:app) do |host|
      execute "rm -rf #{release_path}/html/sites"
      execute "sudo ln -s #{shared_path}/sites #{release_path}/html/sites"
    end
  end

  desc "Run ds build tasks for international"
  task :build_international do
    on roles(:app) do |host|
      puts "THE DEPLOY ENV IS: #{fetch(:deploy_env)} in regular build func"
      execute "cd '#{release_path}'; #{release_path}/bin/ds build --intl"
      execute "cd '#{release_path}/lib/themes/dosomething/paraneue_dosomething'; grunt prod"
      sites.each do |site|
        execute "cd '#{release_path}/html/sites/#{site}'; drush vset --yes ds_version " + ENV['branch']
        execute "cd '#{release_path}/html/sites/#{site}'; echo " + ENV['branch'] + " > VERSION"
      end
    end
  end
end
