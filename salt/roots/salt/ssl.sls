python-dev:
  pkg:
    - installed

python-openssl:
  pkg:
    - installed
    - require:
      - pkg: python-dev

# Example here: http://intothesaltmine.org/install_and_configure_halite_alpha_on_arch_linux.html
# How to call in a State file?
#
# tls.create_ca salt
# tls.create_csr salt
# tls.create_ca_signed_cert salt localhost
#
# Could be explicit calls, e.g.,
#
# sudo salt-call -l debug tls.create_ca_signed_cert salt localhost
#
# But shouldn't that be possible as a declaration here?

tls-create-ca:
  cmd.run:
    - name: sudo salt-call tls.create_ca salt
    - require:
      - pkg: python-openssl

tls-create-csr:
  cmd.run:
    - name: sudo salt-call tls.create_csr salt
    - require:
      - cmd: tls-create-ca

tls-create-cert:
  cmd.run:
    - name: sudo salt-call tls.create_ca_signed_cert salt localhost
    - require:
      - cmd: tls-create-csr

# This doesn't work:
#
# ssl-cert:
#  tls.create_self_signed_cert:
#    - tls_dir: tls
#    - CN: localhost
#    - C: US
#    - ST: New York
#    - L: New York
#    - O: DoSomething.org
#    - emailAddress: machines@dosomething.org

apache2-vhosts-ssl:
  file.managed:
    - name: /etc/apache2/sites-available/default-ssl
    - source: salt://apache2/vhost-ssl.conf
    - require:
      - pkg: apache2
      - cmd: tls-create-cert

apache2-enable-ssl-1:
  cmd.run:
    - name: a2enmod ssl ; service apache2 restart
    - require:
      - file: apache2-vhosts

apache2-enable-ssl-2:
  cmd.run:
    - name: a2ensite default-ssl ; service apache2 restart
    - require:
      - cmd: apache2-enable-ssl-1

apache2-ssl-restart:
  cmd.run:
    - name: service apache2 restart
    - require:
      - cmd: apache2-enable-ssl-2
