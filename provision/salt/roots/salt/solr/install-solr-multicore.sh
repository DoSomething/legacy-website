#!/bin/sh

cd /root
wget http://archive.apache.org/dist/lucene/solr/4.7.0/solr-4.7.0.tgz
tar -vxf solr-4.7.0.tgz
cp -R solr-4.7.0/ /opt/solr
cp solr-4.7.0/example/webapps/solr.war /opt/solr/
cp -r /root/solr-4.7.0/example/lib/ext/* /var/lib/tomcat7/shared
mv /opt/solr/example /opt/solr/multisite
rm -r /opt/solr/multisite/example-DIH
rm -r /opt/solr/multisite/exampledocs/
rm -r /opt/solr/multisite/solr-webapp/

cd /opt/solr/multisite/multicore/core0
mv conf conf.bak
git clone https://gist.github.com/2634e78497a009dbd176.git conf

for COUNTRY in botswana canada congo collection1 ghana kenya indonesia nigeria training uk
do
  cp -r /opt/solr/multisite/multicore/core0 /opt/solr/multisite/multicore/$COUNTRY
  cd /opt/solr/multisite/multicore/$COUNTRY
done

sudo chown -R tomcat7:tomcat7 /opt/solr
sudo service tomcat7 restart
