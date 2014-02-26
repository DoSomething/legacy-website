{% if grains['os'] == 'Ubuntu' %}

drush-aliases:
  file.managed:
    - name: /home/vagrant/.drush/ds.aliases.drushrc.php
    - source: salt://dosomething/ds.aliases.drushrc.php

ssh-host-access:
  file.managed:
    - name: /home/vagrant/.ssh/config
    - source: salt://ssh/config
    - user: vagrant
    - group: vagrant

{% endif %}
