set :deploy_to, "/var/www/beta.dosomething.org"

role :app, %w{dosomething@staging.beta.dosomething.org}

server 'staging.beta.dosomething.org', user: 'dosomething', roles: %w{app}


namespace :deploy do

  after :deploy, :symlink_shared do
    on roles(:app) do |host|

      execute "cd '#{release_path}/html/sites/default'; sudo rm -rf files 2> /dev/null; sudo ln -s #{shared_path}/files files"
      execute "sudo ln -s #{shared_path}/settings.staging.php #{release_path}/html/sites/default/settings.staging.php"
    end
  end

end
