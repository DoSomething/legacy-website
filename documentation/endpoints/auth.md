## Log in

```
POST https://www.dosomething.org/api/v1/auth/login
```

- username: (string) required. The user username.
- password: (string) required. The user password.

Response:

If login was successful, the response contains values to use when making subsequest authenticated requests during the session. See https://www.drupal.org/node/910598 for details.

- token: (string). The header value to post as X-CSRF-Token.
- sessid: (string). The value to set for the Cookie header.
- session_name: (string). The name of the Cookie header to post.
- user: (object). The logged in user.

**Important**

Your autentication cookie is good for one month. Make sure you regenerate it before it expires. Otherwise you'll get an error "Must be logged in!" in response for all API calls that require autentication.


Example request
```
curl https://www.dosomething.org/api/v1/auth/login
 -d '{
  "username":"batman@example.com",
  "password":"imB@tman789Kittycat$"
  }' -H "Content-type: application/json"
  --header "Accept: application/json"
  ```

Example Response
```
{
    "sessid": "OlRJjdQNZyYgxjmF7c0GtUSiO1pCczRCOzqetJJMs5w",
    "session_name": "SESS8de1794320df15914c40c2b37d51eff2",
    "token": "-XmDawHfJ3MRBFGgBvHaF4_RlHq0Dp_xfffGimzr6mM",
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
```


## Log out

```
POST https://www.dosomething.org/api/v1/auth/logout
```

Example request:
```
curl https://www.dosomething.org/api/v1/auth/logout -X POST --header "Content-type: application/json" --header "Accept: application/json" --header "X-CSRF-Token: -XmDawHfJ3MRBFGgBvHaF4_RlHq0Dp_xfffGimzr6mM" --header "Cookie: SESS8de1794320df15914c40c2b37d51eff2=OlRJjdQNZyYgxjmF7c0GtUSiO1pCczRCOzqetJJMs5w"
```

Example response:

```
[true]
```


## Retrieve A Token

Returns the X-CSRF Token for the logged in user.

```
POST http://www.dosomething.org/api/v1/auth/token
```
Example response:

```
  {"token":"TX5fHzUYtOmQyAi9LZkt1hZZlpHiNj9RhmjNocKK-a4"}
```
