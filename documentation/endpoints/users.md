# Users

## Create a user

Create a new Phoenix user with the given profile information.

:warning: __To create new DoSomething.org users, use Northstar's [Create User](https://github.com/DoSomething/northstar/blob/dev/documentation/endpoints/users.md#create-a-user)
endpoint.__

```
POST https://www.dosomething.org/api/v1/users
```

**Body Parameters:**

```js
// Content-Type: application/json

{
  _id: String // required.
  email: String // required.
  mobile: String
  password: String // This is the raw password that the user will use to login.
  birthdate: String  // Expected format YYYY-MM-DD
  first_name: String
  last_name: String
  country: String // Two-letter country code
  user_registration_source: String // Used to indicate if an import or external app has created the User.
}
```

**Example request:**

```sh
curl -X POST -H "Content-Type: application/json" -H "Accept: application/json" \
  -d '{"_id": "58333fbc9a892003da782d0d", "email":"aschachter+nyc@dosomething.org", "password":"password", "birthdate":"1995-12-31", \
       "first_name":"Aaroni","last_name":"Schachterelli","user_registration_source":"services"}' \
  http://dev.dosomething.org:8888/api/v1/users
```

**Example response:**

```js
// 200 Okay

{
    "mail": "aschachter+nyc@dosomething.org",
    "name": "aschachter+nyc@dosomething.org",
    "status": 1,
    "created": 1406642100,
    "field_birthdate": {
        "und": [{
            "value": "1995-12-31",
            "timezone": "UTC",
            "timezone_db": "UTC",
            "date_type": "datetime"
        }]
    },
    "field_first_name": {
        "und": [{
            "value": "Aaroni"
        }]
    },
    "field_last_name": {
        "und": [{
            "value": "Schachterelli"
        }]
    },
    "field_user_registration_source": {
        "und": [{
            "value": "services"
        }]
    },
    "uuid": "6b105ed7-e9c5-4946-a1e3-439e49af4ceb",
    "uid": "1700329",
    "theme": "",
    "signature": "",
    "access": 0,
    "login": 0,
    "language": "",
    "picture": 0,
    "init": "",
    "roles": {
        "2": "authenticated user"
    },
    "field_under_thirteen": {
        "und": [{
            "value": 0
        }]
    },
    "field_address": {
        "und": [{
            "element_key": "user|user|field_address|und|0",
            "thoroughfare": "",
            "premise": "",
            "locality": "",
            "administrative_area": "",
            "postal_code": "",
            "country": "US"
        }]
    }
}
```

## Retrieve a user

Allows for finding a User uid by mobile or email. Returns an array of UIDs for matching users. If no users were found,
an empty array is returned.

This endpoint is only available to a logged in administrator.

```
GET /api/v1/users
```

**Query Parameters:**
  - `email` (string)
  - `mobile` (string)

**Example Request:**
```sh
curl -H "Accept: application/json" http://staging.beta.dosomething.org/api/v1/users?parameters[mobile]=2125550001
```

**Example response:**

```js
// 200 Okay

[
    {
        "uid": "5"
    }
]
```

## Get Member Count

```
POST /api/v1/users/get_member_count
```

**Example Request:**
```sh
curl -X POST http://staging.beta.dosomething.org/api/v1/users/get_member_count
```

**Example Response:**

```js
// 200 Okay

{
  "formatted": "3,596,441",
  "readable": "3.5 million"
}
```

## Get User activity

Returns signup and reportback data, if exists, for given uid and nid.

```
GET /api/v1/users/current/activity?nid={nid}
```

**Example Response:**

```js
// 200 Okay

{
  sid: "1361",
  signed_up: "1422312631",
  source: null,
  rbid: "681",
  created: "1422046181",
  updated: "1422046181",
  quantity: "1",
  why_participated: "12",
  num_participants: null,
  flagged: "0",
  flagged_reason: null,
  fids: [
    "1881"
  ],
  node_title: "Comeback Clothes",
  noun: "Items",
  verb: "Recycled",
  quantity_label: "Items Recycled"
}
```

## Create Password Reset URL

Only available to a logged in administrator. Must include UID of the user in the URL.

```
POST /api/v1/users/{uid}/password_reset_url
```

**Example Response:**

```js
// 200 Okay

[ 'http://dev.dosomething.org:8888/user/reset/1700226/1425495228/P-f-5d6kHLrOXl0VrQfXavgmMjiNz042uihpxJW4jBc' ]
```

## Create Magic Login URL

Only available to a logged in administrator. Must include UID of the user in the URL.

You may optionally append a `?redirect=` query parameter to the returned link to indicate where to redirect
after logging in. For example, use `?redirect=node/1144` to log in & redirect to Teens For Jeans.

```
POST /api/v1/users/{uid}/magic_login_url
```

**Example Response:**

```js
// 200 Okay

{
  "url": "http://dev.dosomething.org:8888/us/user/magic/1700226/1425495228/P-f-5d6kHLrOXl0VrQfXavgmMjiNz042uihpxJW4jBc",
  "expires": "2016-06-08T15:12:52+00:00"
}
```

