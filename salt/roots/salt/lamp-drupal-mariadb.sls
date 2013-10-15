{% if grains['os'] == 'Ubuntu' %}

php5-pkgs:
  pkg.installed:
    - names:
      - php5
      - php5-mysql
      - php5-curl
      - php5-cli
      - php5-cgi
      - php5-dev
      - php-pear
      - php5-gd
      - php5-memcache

apache2:
  pkg:
    - installed

apache2-conf:
  cmd.run:
    - name: sudo cp /vagrant/salt/apache2-vhost-conf /etc/apache2/ ; sudo /etc/init.d/apache2 restart
    - require:
      - pkg: apache2

libapache2-mod-php5:
  pkg:
    - installed

memcached:
  pkg:
    - installed

varnish:
  pkg:
    - installed

pear-drush:
  cmd.run:
    - name: sudo pear channel-discover pear.drush.org ; sudo pear install drush/drush
    - require:
      - pkg: php5-pkgs

mariadb-server-5.5:
  cmd.run:
    - name: sudo apt-key adv --recv-keys --keyserver hkp://keyserver.ubuntu.com:80 0xcbcb082a1bb943db
    - unless: apt-key list | grep -q 0xcbcb082a1bb943db
    - require:
      - file: mariadb-server-5.5
  file:
    - append
    - name: /etc/apt/sources.list
    - text: deb http://ftp.osuosl.org/pub/mariadb/repo/5.5/ubuntu precise main
    - skip_verify: True
  pkg:
    - installed
    - refresh: True
    - require:
      - cmd: apt-update
      - cmd: mariadb-server-5.5

apt-update:
  cmd.run:
    - name: sudo apt-get update

mariadb-client:
  pkg:
    - installed

git:
  pkg:
    - installed

{% endif %}
