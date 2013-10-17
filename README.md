# DoSomething

A private Drupal 7 distribution that will power the DoSomething.org website.

## Building your local environment

DoSomething uses Salty [Vagrant](http://docs-v1.vagrantup.com/v1/docs/getting-started/) for our development box.

To get started, please confirm that you have [Vagrant](http://docs-v1.vagrantup.com/v1/docs/getting-started/) and [VirtualBox](https://www.virtualbox.org/wiki/Downloads) installed.  For more information, go to https://www.virtualbox.org/wiki/Downloads.

To start up your environment:

1. Run `vagrant up` from the application directory.  It will take some time to set everything up.
2. When `vagrant up` is complete, run `vagrant ssh`.  This will take you into the mounted application.

Your environment will be available at localhost:8888.

If you see a "Not Found" error, run the following from `/vagrant`: `sh build.sh`.

Change to the `/vagrant/html` directory (`cd /vagrant/html` after running `vagrant ssh`) to edit your files.

## Contributing

1. Fork
2. Clone your fork locally and make commits and pushes against it.  Add the main repo as an upstream remote to help you keep your fork up to date. (git remote add upstream git@github.com:DoSomething/dosomething.git)
3. Make sure your instance passes tests locally and you create new tests as necessary.
3. Open a pull request against the main repo.  Make sure you reference any open issue that your merge may fix or address.
4. Burger time.
