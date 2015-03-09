Vagrant.configure("2") do |config|

  ## Choose your base box
  config.vm.box = "dosomething/drupal"
  config.vm.box_version = "0.4.0"

  config.vm.provider "virtualbox" do |v|
    v.customize ["modifyvm", :id, "--memory", 3072]
  end

  # SSH Agent forwarding
  config.ssh.forward_agent = true

  if ENV['DS_VAGRANT_MOUNT_NFS']
    # NFS
    config.vm.network :private_network, ip: "10.11.12.13"
    config.vm.synced_folder ".", "/var/www/vagrant", type: "nfs"
  else
    # SSHFS -- reverse mount from within Vagrant box
    config.sshfs.paths = { "/var/www/vagrant" => "../dosomething-mount" }
  end

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

