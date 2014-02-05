{% if grains['os'] == 'Ubuntu' %}

default-jre:
  pkg:
    - installed

xvfb:
  pkg:
    - installed

ant:
  pkg:
    - installed
    - require:
      - pkg: default-jre

firefox:
  pkg:
    - installed

selenium:
  cmd.run:
    - name: cd /vagrant/tests/selenium ; curl -O http://selenium.googlecode.com/files/selenium-server-standalone-2.32.0.jar
    - require:
      - pkg: curl

{% endif %}
