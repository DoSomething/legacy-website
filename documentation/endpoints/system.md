## Connection status

```
POST https://www.dosomething.org/api/v1/system/connect
```

### Anonymous user

Example request:
````
curl https://www.dosomething.org/api/v1/system/connect -X POST --header "Content-type: application/json" --header "Accept: application/json"
````

Example response:
````
{
    "sessid": "3gX-K6doyyVopXe_NpXkFeEyzomTDJTkLgIzW22RXsc",
    "session_name": "SESS8de1794320df15914c40c2b37d51eff2",
    "user": {
        "uid": "0"
    }
}
````

### Authenticated user

Example request:
````
curl https://www.dosomething.org/api/v1/system/connect -X POST --header "Content-type: application/json" --header "Accept: application/json" --header "X-CSRF-Token: -XmDawHfJ3MRBFGgBvHaF4_RlHq0Dp_xfffGimzr6mM" --header "Cookie: SESS8de1794320df15914c40c2b37d51eff2=OlRJjdQNZyYgxjmF7c0GtUSiO1pCczRCOzqetJJMs5w"
````

Example response:
````
{
    "sessid": "TBusFTgEF6-ihAE2VwxXSq-NaZr3hxX6A1fkrdwAc9g",
    "session_name": "SESS6fca668d7b440bf013b2728c61429728",
    "user": {
        "uid": "38",
        "name": "batman",
        "mail": "batman@example.com",
        "theme": "",
        "signature": "",
        "signature_format": "plain_text",
        "created": "1392999246",
        "access": "1405601994",
        "login": "1405601911",
        "status": "1",
        "timezone": "UTC",
        "language": "",
        "picture": "0",
        "data": false,
        "uuid": "8a88c274-d4b4-4f66-b8b7-59029173248c",
        "sid": "KWB0uMKU5IyS2Xgw27v7wnhF9HKoVfJ23dFFt0r7o8s",
        "ssid": "",
        "hostname": "10.0.2.2",
        "timestamp": "1405601911",
        "cache": "0",
        "session": "",
        "roles": {
            "2": "authenticated user"
        }
    }
}
````

## Set a variable

Must be authenticated as an administrator.

```
POST https://www.dosomething.org/api/v1/system/set_variable
```

name: (string) required. The name of the variable to set.
value: (string) required. The value to set it to.

Example request:
````
curl http://dev.dosomething.org:8888/api/v1/system/set_variable -X POST --header "Content-type: application/json" --header "Accept: application/json" --header "X-CSRF-Token: G136HF5yB5ZZawvrsOfU4gw0poUOaQygPrsJlaFakMU" --header "Cookie:SESSd57f2aef87e6d4352ce5db4659184fa7=mKI5_yfoXYBz3r4o95utui4fwBV_lUO1JNN1nEVsPRg" -d '{"name": "dosomething_user_random_variable", "value": 5234232}'
````
