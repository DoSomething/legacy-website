{% if grains['os'] == 'Ubuntu' %}

drush-aliases:
  file.managed:
    - name: /home/vagrant/.drush/ds.aliases.drushrc.php
    - source: salt://dosomething/ds.aliases.drushrc.php

{% endif %}
