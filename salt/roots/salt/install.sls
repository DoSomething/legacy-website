{% if grains['os'] == 'Ubuntu' %}

github-access:
  file.managed:
    - name: /home/vagrant/.ssh/known_hosts
    - source: salt://ssh/known_hosts
    - require:
      - pkg: apache2

drush-make:
  cmd.run:
    - name: cd /vagrant && sudo sh build.sh
    - require:
      - cmd: pear-drush
      - pkg: github-access


{% endif %}
