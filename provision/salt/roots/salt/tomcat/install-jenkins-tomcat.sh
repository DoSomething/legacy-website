#!/bin/sh

cd /var/lib/tomcat7/webapps/
sudo wget http://mirrors.jenkins-ci.org/war/latest/jenkins.war
sudo chmod 655 jenkins.war
sudo service tomcat7 restart
sudo mkdir /usr/share/tomcat7/.jenkins
sudo chown tomcat7:tomcat7 /usr/share/tomcat7/.jenkins
sudo service tomcat7 restart
