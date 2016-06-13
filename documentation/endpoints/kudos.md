
## Create a kudos

```
POST https://www.dosomething.org/api/v1/kudos
```

### Required parameters

- **reportback_item_id**
- **user_id**
- **term_ids**
# Kudos

## Retrieve all kudos

```
GET https://www.dosomething.org/api/v1/kudos
```

### Optional query parameters

- **reportbackitems** _(string|csv)_
 - Comma separated list of reportback ids to get kudos
 - eg: `/kudos?reportbackitems=714,2381`
- **count** _(integer)_ default = `25`
 - Number of kudos to retrieve
 - eg: `/kudos?count=3`


## Retrieve a kudos

```
GET https://www.dosomething.org/api/v1/kudos/10
```
