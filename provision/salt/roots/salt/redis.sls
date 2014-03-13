{% if grains['os'] == 'Ubuntu' %}

redis-server:
  pkg:
    - installed

{% endif %}
