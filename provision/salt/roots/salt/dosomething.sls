{% if grains['os'] == 'Ubuntu' %}

ds-hosts:
  file.managed:
    - name: /etc/hosts
    - source: salt://dosomething/hosts

ds-aliases:
  file.managed:
    - name: /home/vagrant/.drush/blackangus.aliases.drushrc.php
    - source: salt://dosomething/blackangus.aliases.drushrc.php

{% endif %}
