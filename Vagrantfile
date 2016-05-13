Vagrant.configure("2") do |config|

  ## Choose your base box
  config.vm.box = "dosomething/phoenix"
  config.vm.box_version = "1.0.8"

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

  # Mount shared folders
  # NFS
  config.vm.network :private_network, ip: "10.11.12.13"
  config.vm.synced_folder ".", "/var/www/dev.dosomething.org", type: "nfs"

  # Allow `npm link` for Neue
  if File.exists?("/usr/local/lib/node_modules/@dosomething/forge")
    config.vm.synced_folder "/usr/local/lib/node_modules/@dosomething/forge",
      "/usr/local/lib/node_modules/@dosomething/forge",
      owner: "www-data", group: "www-data"
  end

  # Http and https.
  config.vm.network :forwarded_port, guest: 80, host: 8888
  config.vm.network :forwarded_port, guest: 443, host: 8889

  config.vm.host_name = "dev.dosomething.org"

  # With Varnish
  config.vm.network :forwarded_port, guest: 6081, host: 9999

  # Rabbit
  config.vm.network :forwarded_port, guest: 15672, host: 15672

  # Solr.
  config.vm.network :forwarded_port, guest: 8983, host: 8983

  # Welcome message.
  config.vm.provision :shell do |h|
    h.inline = 'cat /var/www/dev.dosomething.org/scripts/install_complete.txt'
  end

end

