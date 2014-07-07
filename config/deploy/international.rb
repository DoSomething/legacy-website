require_relative "./includes/international"

namespace :deploy do

  task :shared_links do
    on roles(:app) do |host|
      execute "rm -rf #{release_path}/html/sites"
      execute "sudo ln -s #{shared_path}/sites #{release_path}/html/sites"
    end
  end

  after :build, 'deploy:shared_links'

end
