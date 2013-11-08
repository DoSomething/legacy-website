require 'yaml'
require 'capistrano/ext/multistage'

# Confirm that the +config/deploy_vars.yml+ file exists.  Please see 
# https://github.com/DoSomething/dosomething/wiki/Setting-up-deploy-vars
# for more details.
vars_file = File.join(File.expand_path('./config'), 'deploy_vars')
if File.exists? vars_file + '.yml'
  # Load the file as a YAML file, into the @config environmental variable.
  @config = YAML.load_file(vars_file + '.yml')
else
  # Fail if the file doesn't exist.
  abort "\e[31mYou need the deploy_vars.yml file to deploy.\e[0m"
end

# Basic capistrano settings.
set :application, "DoSomething.org"
set :repository,  "git@github.com:DoSomething/dosomething.git"

# Basic git access information.  This can be overridden by specifying +scm_user+ and
# +scm_pass+ in the environment-specific group in +deploy_vars.yml+.
if @config['default'] && (@config['default']['scm_user'] && @config['default']['scm_pass'])
  set :scm, :git
  set :scm_user, @config['default']['scm_user']
  set :scm_passphrase, @config['default']['scm_pass']
end

# Basic stages.  Changeable.  This keeps Capistrano up to date with the different
# environments.
set :stages, %w{ production qa staging }
set :default_stage, "production"

# Basic (default) server access.  This can be overridden by specifing +user+ and +password+
# in the environment-specific group in +deploy_vars.yml+.
if @config['default'] && (@config['default']['user'] && @config['default']['password'])
  set :user, @config['default']['user']
  set :password, @config['default']['password']
end

# Forward agents &etc.
ssh_options[:forward_agent] = true
default_run_options[:pty] = true

# By default, don't use Sudo.
set :use_sudo, false

# Very basic deploy block.  This will copy the repository to the specified servers,
# update the database, and run +drush make+.  This can be run with +cap ENVIRONMENT deploy+.
namespace :deploy do
  task :start do; end
  task :stop do; end

  # Run +drush make+ to keep files up-to-date.
  task :make do
    run "cd #{release_path} && drush make --prepare-install --no-gitinfofile --no-cache build-dosomething.make html"
  end
  # Run +drush updb -y+ to keep the database up-to-date.
  task :updb do
    run "cd #{release_path} && drush updb -y"
  end
  # Run +drush cc all+ to clear caches.
  task :cache_clear do
    run "cd #{release_path} && drush cc all"
  end
end

after 'deploy:make', 'deploy:updb'
after 'deploy:updb', 'deploy:cache_clear'
