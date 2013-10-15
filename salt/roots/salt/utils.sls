{% if grains['os'] == 'Ubuntu' %}

curl:
  pkg:
    - installed

sendmail:
  pkg:
    - installed

{% endif %}
