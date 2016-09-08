# Magicks

## Cast magick action

```
GET https://www.dosomething.org/api/v1/magicks?action=action_name
```

### Required Query Parameters
- **action** _(string)_
  + Specify the action to execute
  + eg: `/magicks?action=signup`

### Optional Query Parameters
- **user** _(string)_
  + Specify a user id
  + eg: `/magicks?action=signup&user=1700013` 
- **campaign** _(string)_
  + Specify a campaign id
  + eg: `/magicks?action=signup&campaign=1280`
- **campaign_run** _(string)_
  + Specify a campaign run id
  + eg: `/magicks?action=signup&campaign_run=1832`
- **key** _(string)_
  + Set a key token
  + eg: `/magicks?action=signup&key=asdhd74naduhd73`
- **source** _(string)_
  + Set a source where action originated from
  + eg: `/magicks?action=signup&source=email_newsletter` 

### Required Query Parameters By Action
To properly execute certain magicks actions, the actions require passing along certain query parameters. The following specifies the required parameters along with optional parameters for each action:

#### Action: Signup
```
GET https://www.dosomething.org/api/v1/magicks?action=signup&user=1700013&campaign=1280&campaign_run=1832&key=somecr4zyl0ngstr1ng
```

- **user** (required)
- **campaign** (required)
- **campaign_run** (required)
- **key** (required)
- **source** (optional)
