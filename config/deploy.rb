require 'yaml'
require 'capistrano/ext/multistage'

vars_file = File.join(File.expand_path('./config'), 'deploy_vars')
if File.exists? vars_file + '.yml'
  @config = YAML.load_file(vars_file + '.yml')
else
  abort "You need the deploy_vars.yml file to deploy."
end

set :application, "DoSomething.org"
set :repository,  "git@github.com:DoSomething/dosomething.git"
set :branch, 'master'
set :stages, %w{ production qa staging }
set :default_stage, "production"

if @config['default']
  set :user, @config['default']['user']
  set :password, @config['default']['password']
end

#ssh_options[:keys] = [ENV['CAP_PRIVATE_KEY']]
ssh_options[:forward_agent] = true
default_run_options[:pty] = true

set :deploy_to, '/var/www/v2'
set :use_sudo, false

namespace :deploy do
  task :start do; end
  task :stop do; end
  task :go, stage: "qa" do
    run "cd /var/www && ls -l"
    abort "Testing."
  end
end

