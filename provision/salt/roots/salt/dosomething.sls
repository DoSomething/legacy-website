{% if grains['os'] == 'Ubuntu' %}

ssh-host-access:
  file.managed:
    - name: /home/vagrant/.ssh/config
    - source: salt://ssh/config
    - user: vagrant
    - group: vagrant

/var/www/vagrant:
  file.directory:
    - user: vagrant
    - group: vagrant
    - mode: 755
    - makedirs: True

webroot-internal:
  cmd.run:
    - name: 'tar czf /var/www/vagrant.tgz /vagrant ; cd /var/www ; tar xzf vagrant.tgz ; rm vagrant.tgz'
    - unless: test -d /var/www/vagrant
    - require:
      - pkg: apache2

{% endif %}
