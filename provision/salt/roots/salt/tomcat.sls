{% if grains['os'] == 'Ubuntu' %}

solr-tomcat:
  pkg:
    - installed
  file.managed:
    - name: /var/lib/tomcat6/conf/server.xml
    - source: salt://tomcat/server.xml
    - require:
      - pkg: solr-tomcat

solr-drupal-conf:
  file.managed:
    - name: /etc/solr/conf/schema.xml
    - source: salt://solr/schema.xml
    - require:
      - pkg: solr-tomcat

solr-solr-conf:
  file.managed:
    - name: /etc/solr/conf/solrconfig.xml
    - source: salt://solr/solrconfig.xml
    - require:
      - pkg: solr-tomcat

tomcat6:
  service.running:
    - enable: False
    - restart: False
    - watch:
      - file: /var/lib/tomcat6/conf/*
    - require:
      - pkg: solr-tomcat

jenkins-manual:
  cmd.run:
    - name: sh /srv/salt/tomcat/install-jenkins-tomcat.sh > /dev/null
    - require:
      - pkg: solr-tomcat

{% endif %}