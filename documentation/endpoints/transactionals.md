# Transactionals

## Create a user

Send a transactional message and add user to the appropriate MailChimp and Mobile Commons lists.

This endpoint requires administrative privileges.

```
POST https://www.dosomething.org/api/v1/transactionals
```

**Body Parameters:**

```js
// Content-Type: application/json

{
  id: String // required, Northstar ID.
  template: String // required, "register"
}
```

**Example request:**

```sh
curl -X POST -H "Content-Type: application/json" -H "Accept: application/json" \
  -d '{"id": "58333fbc9a892003da782d0d", "template":"register"}' \
  http://dev.dosomething.org:8888/api/v1/transactionals
```

**Example response:**

```js
// 200 Okay

{
    "success": true
}
```
