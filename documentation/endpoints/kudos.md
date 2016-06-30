# Kudos

## Create a kudos

```
POST https://www.dosomething.org/api/v1/kudos
```

### Required parameters

- **reportback_item_id**
- **term_ids**
- **user_id**


## Retrieve all kudos

```
GET https://www.dosomething.org/api/v1/kudos
```

### Optional query parameters

**NOTE: The following query parameters no longer work with this endpoint and will soon be deprecated or refactored!**

- **reportbackitems** _(string|csv)_
 - Comma separated list of reportback ids to get kudos
 - eg: `/kudos?reportbackitems=714,2381`
- **count** _(integer)_ default = `25`
 - Number of kudos to retrieve
 - eg: `/kudos?count=3`

Example request:
```
https://www.dosomething.org/api/v1/kudos
```

Example response:
```
{
  kudos: {
    data: [
      {
        term: {
          id: "641",
          name: "heart",
          total: 24
        },
        current_user: {
          drupal_id: "4878998",
          reacted: tue,
          kudos_id: "1015"
        }
      }
    ]
  }
}
```


## Retrieve a kudos

```
GET https://www.dosomething.org/api/v1/kudos/:id
```

Example request:
```
https://www.dosomething.org/api/v1/kudos/1278
```

Example response:
```
{
  data: {
    id: "1278",
    term: {
      id: "641",
      name: "heart"
    },
    reportback_item: {
      id: "828"
    },
    user: {
      drupal_id: "4878998",
      id: "55772c73jdh6482d3d8b4599",
      first_name: "John",
      last_name: "Smith",
      photo: null,
      country: "US"
    },
    uri: "http://dev.dosomething.org:8888/api/v1/kudos/1278"
  }
}
```
