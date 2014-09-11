Vagrant.configure("2") do |config|

  ## Choose your base box
  config.vm.box = "dosomething/drupal"

  config.vm.provider "virtualbox" do |v|
    v.customize ["modifyvm", :id, "--memory", 3072]
  end

  # SSH Agent forwarding
  config.ssh.forward_agent = true

  # SSHFS -- reverse mount from within Vagrant box
  config.sshfs.paths = { "/var/www/vagrant" => "../dosomething-mount" }

  # Bare Apache httpd (http and https)
  config.vm.network :forwarded_port, guest: 8888, host: 8888
  config.vm.network :forwarded_port, guest: 8889, host: 8889

  config.vm.host_name = "dev.dosomething.org"

  # With Varnish
  config.vm.network :forwarded_port, guest: 6081, host: 9999

  # Tomcat with Jenkins and Solr
  config.vm.network :forwarded_port, guest: 8080, host: 8080

  config.vm.provision :shell, :inline => 'more /vagrant/scripts/install_complete.txt'
end

