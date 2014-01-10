{% if grains['os'] == 'Ubuntu' %}

github-access:
  file.managed:
    - name: /home/vagrant/.ssh/known_hosts
    - source: salt://ssh/known_hosts
    - require:
      - pkg: apache2

db-prepare:
  cmd.run:
    - name: mysqladmin -uroot create dosomething
  require:
    - pkg: mysql-server

db-dump-folder:
  cmd.run:
    - name: mkdir -p ~/db_dumps
  require:
    - cmd: db-prepare

ds-utils:
  cmd.run:
    - name: sudo ln -s /vagrant/bin/ds /usr/local/bin/ds

{% endif %}
