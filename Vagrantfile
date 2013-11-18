Vagrant.configure("2") do |config|
  ## Chose your base box
  config.vm.box = "precise64"
  config.vm.box_url = "http://files.vagrantup.com/precise64.box"
  
  config.vm.provider "virtualbox" do |v|
    v.customize ["modifyvm", :id, "--memory", 1024]
  end

  # SSH Agent forwarding
  config.ssh.forward_agent = true

  ## For masterless, mount your salt file root
  config.vm.synced_folder "salt/roots/", "/srv/"
  
  # Bare Apache httpd (http and https)
  config.vm.network :forwarded_port, guest: 8888, host: 8888
  config.vm.network :forwarded_port, guest: 443, host: 8889
  
  # With Varnish
  config.vm.network :forwarded_port, guest: 6081, host: 9999
  
  # Tomcat with Jenkins and Solr
  config.vm.network :forwarded_port, guest: 9090, host: 11111
  
  ## Use all the defaults:
  config.vm.provision :salt do |salt|
    # Uncomment to see Salt output
    salt.verbose = true
    salt.minion_config = "salt/minion.conf"
    salt.run_highstate = true
  end
  config.vm.provision :shell, :inline => 'cd /vagrant && more install_complete.txt'
end
