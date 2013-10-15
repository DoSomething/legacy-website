{% if grains['os'] == 'Ubuntu' %}

mysql-setup-1:
  cmd.run:
    - name: sudo mysql -e 'create database drupal;'

{% endif %}