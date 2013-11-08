require 'yaml'
require 'capistrano/ext/multistage'

vars_file = File.join(File.expand_path('./config'), 'deploy_vars')
if File.exists? vars_file + '.yml'
  @config = YAML.load_file(vars_file + '.yml')
else
  abort "\e[31mYou need the deploy_vars.yml file to deploy.\e[0m"
end

set :application, "DoSomething.org"
set :repository,  "git@github.com:DoSomething/dosomething.git"
set :deploy_via, :remote_cache

if @config['default'] && (@config['default']['scm_user'] && @config['default']['scm_pass'])
  set :scm, :git
  set :scm_user, @config['default']['scm_user']
  set :scm_passphrase, @config['default']['scm_pass']
end

set :stages, %w{ production qa staging }
set :default_stage, "production"

if @config['default']
  set :user, @config['default']['user']
  set :password, @config['default']['password']
end

ssh_options[:forward_agent] = true
default_run_options[:pty] = true

set :use_sudo, false

namespace :deploy do
  task :start do; end
  task :stop do; end
  task :make do
    run "cd #{release_path} && drush make --prepare-install --no-gitinfofile --no-cache build-dosomething.make html"
  end
  task :blah do
    run "ls -l"
  end
end
