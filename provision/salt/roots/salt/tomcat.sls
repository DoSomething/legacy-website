{% if grains['os'] == 'Ubuntu' %}

tomcat7-packages:
  pkg.installed:
    - pkgs:
      - tomcat7
      - tomcat7-admin
      - tomcat7-common
      - tomcat7-user

tomcat-users:
  file.managed:
    - name: /etc/tomcat7/tomcat-users.xml
    - source: salt://tomcat/tomcat-users.xml
    - user: root
    - group: tomcat7
    - require:
      - pkg: tomcat7-packages

jenkins-manual:
  cmd.run:
    - name: sh /srv/salt/tomcat/install-jenkins-tomcat.sh > /dev/null
    - require:
      - pkg: tomcat7-packages

solr-manual:
  cmd.run:
    - name: sh /srv/salt/solr/install-solr-multicore.sh
    - require:
      - pkg: tomcat7-packages

solr-tomcat:
  file.managed:
    - name: /etc/tomcat7/Catalina/localhost/solr.xml
    - source: salt://solr/solr.xml
    - user: root
    - group: root
    - require:
      - pkg: tomcat7-packages

solr-multicore:
  file.managed:
    - name: /opt/solr/multisite/multicore/solr.xml
    - source: salt://solr/solr-multicore.xml
    - user: tomcat7
    - group: tomcat7
    - require:
      - pkg: tomcat7-packages

tomcat7:
  service.running:
    - enable: True
    - restart: True
    - watch:
      - file: /etc/tomcat7/*

{% endif %}
