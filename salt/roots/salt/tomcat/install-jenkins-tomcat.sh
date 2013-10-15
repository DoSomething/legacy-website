#!/bin/sh

cd /var/lib/tomcat6/webapps/
sudo wget http://mirrors.jenkins-ci.org/war/latest/jenkins.war
sudo chmod 655 jenkins.war
sudo service tomcat6 restart
sudo mkdir /usr/share/tomcat6/.jenkins
sudo chown tomcat6:nogroup /usr/share/tomcat6/.jenkins
sudo service tomcat6 restart
