{% if grains['os'] == 'Ubuntu' %}

drush-make:
  cmd.run:
    - name: cd /vagrant && drush make drupal-org-core.make html
    - require:
      - cmd: pear-drush

database-setup:
  cmd.run:
    - name: sudo mysqladmin -uroot create dosomething
    - require:
      - cmd: drush-make

site-install:
  cmd.run:
    - name: cd /vagrant/html && drush site-install standard -y --db-url=mysql://root@localhost/dosomething --site-name=DoSomething
    - require:
      - cmd: database-setup

site-symlinks:
  cmd.run:
    - name: cd /vagrant && ln -s /vagrant/files /vagrant/html/files
    - require:
      - cmd: site-install

{% endif %}
