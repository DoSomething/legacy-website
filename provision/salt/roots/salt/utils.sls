{% if grains['os'] == 'Ubuntu' %}

curl:
  pkg:
    - installed

sendmail:
  pkg:
    - installed

python-pip:
  pkg:
    - installed

git:
  pkg:
    - latest

git-repo:
  pkgrepo.managed:
    - ppa: git-core/ppa
    - require_in:
      - pkg: git

vim:
  pkg:
    - installed

bash-fix:
  cmd.run:
    - name: sudo rm /bin/sh && sudo ln -s /bin/bash /bin/sh

America/New_York:
  timezone.system

/home/vagrant/.bashrc:
  file.uncomment:
    - regex: 'force_color_prompt=yes'

{% endif %}
