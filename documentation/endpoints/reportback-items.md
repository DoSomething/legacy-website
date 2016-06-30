## Retrieve all reportback items

```
GET https://www.dosomething.org/api/v1/reportback-items
```

## Optional query Parameters

- **campaigns** _(string|csv)_
  - Comma separated list of campaign ids
  - eg: `/reportback-items?campaigns=1080,362`
- **status** _(string)_ default = `promoted,approved`
  - Comma separated list of statuses
   - These include _promoted_, _approved_, _excluded_, _flagged_
   - Only _promoted_ and _approved_ are available to anonymous requests.
   - eg: `/reportback-items?status=promoted`
- **count** _(integer)_ default = `25`
  - Number of items to retrieve
  - If paginated, number to show per page
  - eg: `/reportback-items?count=10`
- **random** _(boolean)_ default = `false`
  - Boolean to indicate whether to retrieve items randomly
  - eg: `/reportback-items?random=true`
- **page** _(integer)_ default = `1`
  - If data is paginated, can specify a specific page of retrieved data
- **load_user** _(boolean)_
  - Flag to indicate whether to make call to northstar to retrieve full user data.
  - ex: `/reportbacks?load_user=true`

Example request:
```
https://www.dosomething.org/api/v1/reportback-items?campaigns=1321,362,1283&status=promoted,approved&count=3&random=true
```

Example response:
```
{
  meta : {
    pagination: {
      total: 166,
      per_page: 3,
      current_page: 1,
      total_pages: 56,
      links: {
        prev_uri: null,
        next_uri: "https://www.dosomething.org/api/v1/reportback-items?&campaigns=1321,362,1283&status=promoted,approved&count=3&page=2"
      }
    }
  },
  data: [
    {
      id: "572",
      status: "approved",
      caption: "DoSomething? Just did!",
      uri: "https://www.dosomething.org/api/v1/reportback-items/572",
      media: {
        uri: "https://www.dosomething.org/sites/default/files/styles/480x480/public/reportbacks/362/image12.jpeg",
        type: "image"
      },
      created_at: "1402439166",
      kudos: {
        data: [
          {
            term: {
              id: "641",
              name: "heart",
              total: 15
            },
            "current_user": {
              drupal_id: "4878998",
              reacted: false,
              kudos_id: null
            }
          }
        ]
      },
      reportback: {
        id: "78",
        created_at: "1395858155",
        updated_at: "1423857962",
        quantity: 20,
        why_participated: "Nulla vitae elit libero, a pharetra augue.",
        flagged: false
      },
      campaign: {
        id: "362",
        title: "Comeback Clothes"
      },
      user: {
        id: "2688313"
      }
    },
    {
      id: "658",
      status: "approved",
      caption: "DoSomething? Just did!",
      uri: "https://www.dosomething.org/api/v1/reportback-items/658",
      media: {
        uri: "https://www.dosomething.org/sites/default/files/styles/480x480/public/reportbacks/362/image42.jpeg",
        type: "image"
      },
      created_at: "1402428343",
      kudos: {
        data: [
          {
            term: {
              id: "641",
              name: "heart",
              total: 15
            },
            "current_user": {
              drupal_id: "4878998",
              reacted: true,
              kudos_id: "1015"
            }
          }
        ]
      },
      reportback: {
        id: "89",
        created_at: "1394658072",
        updated_at: "1394743866",
        quantity: 12,
        why_participated: "Because I want everybody to look cool!",
        flagged: false
      },
      campaign: {
        id: "362",
        title: "Comeback Clothes"
      },
      user: {
        id: "486418",
        first_name: "John",
        last_name: "Dow",
        photo: "https://avatar.dosomething.org/uploads/avatars/55566327bffebc0b3e8b45a5.jpeg",
        country: "US"
      }
    },
    {
      id: "5874",
      status: "approved",
      caption: "Morbi leo risus porta ac.",
      uri: "https://www.dosomething.org/api/v1/reportback-items/5874",
      media: {
        uri: "https://www.dosomething.org/sites/default/files/styles/480x480/public/reportbacks/1321/image679.jpeg",
        type: "image"
      },
      created_at: "1423757294",
      kudos: {
        data: []
      },
      reportback: {
        id: "895",
        created_at: "1423757294",
        updated_at: "1423757423",
        quantity: 1,
        why_participated: "Duis mollis, est non commodo luctus, nisi erat porttitor ligula, eget lacinia odio sem nec elit.",
        flagged: false
      },
      campaign: {
        id: "1321",
        title: "Hunt Day 5: Band-Aid Brigade"
      },
      user: {
        id: "4878998"
        first_name: "John",
        last_name: "Smith",
        photo: "https://avatar.dosomething.org/uploads/avatars/55566327bffebc0b3e8b45a7.jpeg",
        country: "US"
      }
    }
  ]
}
```


## Retrieve a reportback item

```
GET https://www.dosomething.org/api/v1/reportback-items/:id
```

Example request:

```
https://www.dosomething.org/api/v1/reportback-items/85071
```

Example response:

```
{
  data: {
    id: "85071",
    status: "approved",
    caption: "For a great cause!",
    uri: "https://www.dosomething.org/api/v1/reportback-items/85071",
    media: {
      uri: "https://dosomething-a.akamaihd.net/sites/default/files/styles/480x480/public/reportbacks/362/image.jpg",
      type: "image"
    },
    created_at: "1426110120",
    kudos: {
      data: [
        {
          term: {
            id: "641",
            name: "heart",
            total: 36
          },
          "current_user": {
            drupal_id: "4878998",
            reacted: true,
            kudos_id: "1099"
          }
        }
      ]
    },
    reportback: {
      id: "63344",
      created_at: "1425694214",
      updated_at: "1426697649",
      quantity: 151,
      why_participated: "So many clothes and other textiles go to waste every year because they are unwanted and too worn to go to Goodwill. This is a great way to get rid of those clothes and help out the environment too!",
      flagged: false
    },
    campaign: {
      id: "362",
      title: "Comeback Clothes"
    },
    user: {
      id: "1892717"
      first_name: "John",
      last_name: "Dow",
      photo: "https://avatar.dosomething.org/uploads/avatars/55566327bffebc0b3e8b45a5.jpeg",
      country: "US"
    }
  }
}
```



## Review a reportback file

Only available to Users with `view any reportback` permissions.

```
POST https://www.dosomething.org/api/v1/reportback_files/[fid]/review
```

  - **status**: (string) required.
    The status to set on the Reportback File. Possible values: `approved`, `promoted`, `excluded`, `flagged`

  - **flagged_reason**: (string)
    If status is set to `flagged`, the reason why.

  - **delete**: (int)
    If status is set as `flagged`, sending a `delete` value of 1 will delete the Reportback File from the server.
