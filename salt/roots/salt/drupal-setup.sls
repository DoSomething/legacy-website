{% if grains['os'] == 'Ubuntu' %}

drupal-setup-3:
  cmd.run:
    - name: cd /vagrant ; drush make https://raw.github.com/mshmsh5000/classic/master/build-classic.make drupal
    - require:
      - cmd: pear-drush
      - pkg: mysql-server
      - pkg: php5-pkgs
      - pkg: apache2
      - pkg: git
      - pkg: sendmail

drupal-setup-4:
  cmd.run:
    - name: cd /vagrant/drupal ; sudo chmod -R 777 sites/all/modules
    - require:
      - cmd: drupal-setup-3

drupal-setup-5:
  cmd.run:
    - name: cd /vagrant/drupal ; drush si classic --sites-subdir=default --db-url=mysql://root:@127.0.0.1/drupal --account-name=admin --account-pass=classic --site-mail=mholford@dosomething.org --site-name="Drupal Classic Profile" --yes
    - require:
      - cmd: drupal-setup-4

drupal-setup-6:
  cmd.run:
    - name: cd /vagrant/drupal ; drush up --yes ; drush cc all --yes
    - require:
      - cmd: drupal-setup-5

{% endif %}