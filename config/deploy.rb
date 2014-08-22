require 'pp'
# config valid only for Capistrano 3.1
lock '3.1.0'

set :application, 'beta.dosomething.org'
set :repo_url, 'git@github.com:DoSomething/dosomething.git'

set :branch, "dev"
if ENV['branch']
    set :branch, ENV['branch'] || 'dev'
end

set :ssh_options, { :forward_agent => true }

set :pty, true
