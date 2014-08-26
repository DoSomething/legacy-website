{% if grains['os'] == 'Ubuntu' %}

nodejs:
  pkg:
    - installed

npm-repo:
  pkgrepo.managed:
    - ppa: chris-lea/node.js
    - require_in:
      - pkg: nodejs

npm-packages:
  npm.installed:
    - names:
      - bower
      - grunt-cli
      - phantomjs
      - casperjs
      - mocha-phantomjs 

{% endif %}
