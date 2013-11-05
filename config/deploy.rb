require 'yaml'
require 'capistrano/ext/multistage'

vars_file = File.join(File.expand_path('./config'), 'deploy_vars')
if File.exists? vars_file + '.yml'
  config = YAML.load_file(vars_file + '.yml')
else
  abort "You need the deploy_vars.yml file to deploy."
end

set :application, "DoSomething.org"
set :repository,  "git@github.com:DoSomething/dosomething.git"
set :branch, 'master'
set :stages, %w{ production qa staging }
set :default_stage, "production"

set :gateway, 'admin.dosomething.org:38383'
server "10.179.105.161", "10.179.109.96", "10.179.111.84", "10.179.38.7", :app, :web, :db, primary: true

server 'db.dosomething.org', :db
set :port, '38383'
set :user, config['user']
set :password, config['password']
#ssh_options[:keys] = [ENV['CAP_PRIVATE_KEY']]
ssh_options[:forward_agent] = true
default_run_options[:pty] = true

set :deploy_to, '/var/www/v2'
set :use_sudo, false

namespace :deploy do
  task :start do; end
  task :stop do; end
  task :go do
    p "!"
    abort
  end
end

