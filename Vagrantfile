Vagrant.configure("2") do |config|

  ## Choose your base box
  config.vm.box = "dosomething/drupal"
  config.vm.box_version = "1.0.0.rc1"

  config.vm.provider "virtualbox" do |v|
    v.customize ["modifyvm", :id, "--memory", 3072]
    # Fixes slow DNS on virtual Ubuntu 14.04.
    v.customize ["modifyvm", :id, "--natdnshostresolver1", "on"]
  end

  # Use custom created user to manage vagrant.
  config.ssh.username = 'dosomething'

  # Since authorized keys were prepopulated, vagrant needs a path to your key.
  config.ssh.private_key_path = '~/.ssh/id_rsa'

  # SSH Agent forwarding
  config.ssh.forward_agent = true

  if ENV['DS_VAGRANT_MOUNT_NFS']
    # NFS
    config.vm.network :private_network, ip: "10.11.12.13"
    config.vm.synced_folder ".", "/var/www/dev.dosomething.org", type: "nfs"

    # Allow `npm link` for Neue
    if File.exists?("/usr/local/lib/node_modules/dosomething-neue")
      config.vm.synced_folder "/usr/local/lib/node_modules/dosomething-neue",
        "/usr/local/lib/node_modules/dosomething-neue",
        :owner => "www-data",
        :group => "www-data"
    end
  else
    # SSHFS -- reverse mount from within Vagrant box
    config.sshfs.paths = { "/var/www/dev.dosomething.org" => "../dosomething-mount" }
  end

  # Http and https.
  config.vm.network :forwarded_port, guest: 80, host: 8888
  config.vm.network :forwarded_port, guest: 443, host: 8889

  config.vm.host_name = "dev.dosomething.org"

  # With Varnish
  config.vm.network :forwarded_port, guest: 6081, host: 9999

  # Solr.
  config.vm.network :forwarded_port, guest: 8983, host: 8983

  config.vm.provision :shell, :inline => 'more /vagrant/scripts/install_complete.txt'
end

