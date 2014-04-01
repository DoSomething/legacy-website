set :deploy_to, "/var/www/qa-beta"

role :app, %w{dosomething@blackangus.dosomething.org}

server 'blackangus.dosomething.org', user: 'dosomething', roles: %w{app}

namespace :deploy do

  task :shared_links do
    on roles(:app) do |host|
      execute "cd '#{release_path}/html/sites/default'; sudo rm -rf files 2> /dev/null; sudo ln -s #{shared_path}/files files"

      execute "printf 'User-agent: *\nDisallow: /' > #{release_path}/html/robots.txt"
      #execute "drush rsync @ds.staging:%files #{shared_path} -y"
    end
  end

  after :build, 'deploy:shared_links'

end
