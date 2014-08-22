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
      - php-apc

php5-cli-config:
  file.managed:
    - name: /etc/php5/cli/php.ini
    - source: salt://php5/cli/php.ini
    - require:
      - pkg: php5-pkgs

pear-misc:
  cmd.run:
    - name: /bin/sh /srv/salt/php5/pear-install.sh > /dev/null
    - require:
      - pkg: php5-pkgs

pecl-install-1:
  file.managed:
    - name: /etc/php5/conf.d/apc.ini
    - source: salt://php5/apc.ini
    - require:
      - pkg: php5-pkgs

pecl-install-2:
  file.managed:
    - name: /etc/php5/conf.d/uploadprogress.ini
    - source: salt://php5/uploadprogress.ini
    - require:
      - pkg: php5-pkgs

apache2-env:
  file.managed:
    - name: /etc/apache2/envvars
    - source: salt://apache2/envvars
    - require:
      - pkg: apache2

apache2:
  pkg:
    - installed
  file.managed:
    - name: /etc/apache2/ports.conf
    - source: salt://apache2/ports.conf
    - require:
      - pkg: apache2

apache2-vhosts:
  file.managed:
    - name: /etc/apache2/sites-available/default
    - source: salt://apache2/vhost.conf
    - require:
      - pkg: apache2

apache2-conf:
  file.managed:
    - name: /etc/apache2/apache2.conf
    - source: salt://apache2/apache2.conf
    - require:
      - file: apache2-vhosts

apache2-mods:
  cmd.run:
    - name: sudo a2enmod rewrite
    - require:
      - file: apache2-conf
      - pkg: php5-pkgs

apache2-restart:
  cmd.run:
    - name: sudo chown -R vagrant:vagrant /var/log/apache2 ; sudo chown -R vagrant:vagrant /var/lock/apache2 ; sudo service apache2 restart
    - require:
      - cmd: apache2-mods

drupal-files:
  cmd.run:
    - name: mkdir -p /vagrant/files ; chmod 777 /vagrant/files

libapache2-mod-php5:
  pkg:
    - installed
    - require:
      - pkg: apache2
  file.managed:
    - name: /etc/php5/apache2/php.ini
    - source: salt://php5/apache2/php.ini
    - require:
      - pkg: php5-pkgs

memcached:
  pkg:
    - installed

varnish:
  pkg:
    - installed
  service.running:
    - enable: True
    - restart: True
    - watch:
      - file: /etc/varnish/default.vcl
      - file: /etc/default/varnish

varnish-config:
  file.managed:
    - name: /etc/varnish/default.vcl
    - source: salt://varnishd/lullabot_varnish3.vcl
    - require:
      - pkg: varnish

varnish-default:
  file.managed:
    - name: /etc/default/varnish
    - source: salt://varnishd/etc-default-varnish
    - require:
      - pkg: varnish

varnish-secret:
  file.managed:
    - name: /etc/varnish/secret
    - source: salt://varnishd/secret
    - require:
      - pkg: varnish

mysql-common:
  pkg:
    - installed

mysql-client:
  pkg:
    - installed
    - require:
      - pkg: mysql-common

mysql-server:
  pkg:
    - installed
    - require:
      - pkg: mysql-client

apt-update:
  cmd.run:
    - name: sudo apt-get update

solr:
  host.present:
    - ip: 127.0.0.1

international.staging:
  host.present:
    - ip: 98.129.111.174
    - names:
      - international.staging
      - international.qa

solr_port:
   environ.set:
     - name: DS_APACHESOLR_PORT
     - value: 8080
     - update_minion: True

finder_url:
  environ.set:
     - name: DS_FINDER_URL
     - value: http://solr.dev.dosomething.org


{% endif %}
