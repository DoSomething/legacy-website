{% if grains['os'] == 'Ubuntu' %}

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

stage-file-proxy:
  cmd.run:
    - name: 'drush en -y stage_file_proxy'
    - user: vagrant

{% endif %}
