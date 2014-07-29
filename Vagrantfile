Vagrant.configure("2") do |config|
  ## Chose your base box
  config.vm.box = "precise64"
  config.vm.box_url = "http://files.vagrantup.com/precise64.box"

  config.vm.provider "virtualbox" do |v|
    v.customize ["modifyvm", :id, "--memory", 3072]
  end

  # SSH Agent forwarding
  config.ssh.forward_agent = true

  ## For masterless, mount your salt file root
  config.vm.synced_folder "provision/salt/roots/", "/srv/"

  # SSHFS -- reverse mount from within Vagrant box
  config.sshfs.paths = { "/var/www/vagrant" => "../dosomething-mount" }
  # config.sshfs.username = "alternateuser"

  # Bare Apache httpd (http and https)
  config.vm.network :forwarded_port, guest: 8888, host: 8888
  config.vm.network :forwarded_port, guest: 8889, host: 8889

  config.vm.host_name = "dev.dosomething.org"

  # With Varnish
  config.vm.network :forwarded_port, guest: 6081, host: 9999

  # Tomcat with Jenkins and Solr
  config.vm.network :forwarded_port, guest: 8080, host: 8080

  ## Use all the defaults:
  config.vm.provision :salt do |salt|
    # Uncomment to see Salt output
    # salt.verbose = true
    salt.minion_config = "provision/salt/minion.conf"
    salt.run_highstate = true
  end
  config.vm.provision :shell, :inline => 'more /vagrant/provision/install_complete.txt'
end
