{% if grains['os'] == 'Ubuntu' %}

drush-aliases:
  file.managed:
    - name: /home/vagrant/.drush/ds.aliases.drushrc.php
    - source: salt://dosomething/ds.aliases.drushrc.php

drush-policy:
  file.managed:
    - name: /home/vagrant/.drush/policy.drush.inc
    - source: salt://dosomething/policy.drush.inc

ssh-host-access:
  file.managed:
    - name: /home/vagrant/.ssh/config
    - source: salt://ssh/config
    - user: vagrant
    - group: vagrant

webroot-internal:
  cmd.run:
    - name: 'tar czf /var/www/vagrant.tgz /vagrant ; cd /var/www ; tar xzf vagrant.tgz ; rm vagrant.tgz'
    - unless: test -d /var/www/vagrant
    - require:
      - pkg: apache2

{% endif %}
