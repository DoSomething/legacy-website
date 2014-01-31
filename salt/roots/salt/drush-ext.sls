{% if grains['os'] == 'Ubuntu' %}

get-terminus:
  cmd.run:
    - name: 'git clone https://github.com/pantheon-systems/terminus.git /home/vagrant/.drush/terminus; sudo chown -R vagrant:vagrant /home/vagrant/.drush'
    - unless: test -f /home/vagrant/.drush/terminus

update-terminus:
  cmd.wait:
    - name: 'cd /home/vagrant/.drush/terminus; composer update --no-dev; drush cc drush'
    - watch:
      - cmd: get-terminus

drush-make-local:
  cmd.wait:
    - name: 'drush dl make_local-6.x-1.0'
    - user: vagrant
    - watch:
      - cmd: get-terminus

{% endif %}
