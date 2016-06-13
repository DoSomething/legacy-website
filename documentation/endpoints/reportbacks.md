## Retrieve all reportbacks

```
GET https://www.dosomething.org/api/v1/reportbacks
```

### Optional Query Parameters

- **campaigns** _(string|csv)_
  - The ids of specified campaigns to get reportbacks
  - ex: `/reportbacks?campaigns=1080,362`
- **status** _(string|csv)_
  - Comma delimited list of reportback statuses to collect reportbacks for
  - ex: `/reportbacks?status=promoted`
- **count** _(integer)_
  - The number of reportbacks to retrieve
  - ex: `/reportbacks?count=5`
- **random** _(boolean)_
  - Boolean to indicate whether to retrieve reportbacks in random order
  - ex: `/reportbacks?random=true`
- **page** _(integer)_
  -  For pagination, specify page of reportbacks to return in the response
  - ex: `/reportbacks?page=3`
- **load_user** _(boolean)_
  - Flag to indicate whether to make call to northstar to retrieve full user data.
  - ex: `/reportbacks?load_user=true`
- **flagged** _(boolean)_
  - Boolean to indicate whether to also retrieve flagged reportbacks.
  - ex: `/reportbacks?flagged=true`
- **runs** _(string|csv)_
 - Comma separated list of campaign run ids to get reportbacks
 - eg: `/reportbacks?runs=6737`

## Retrieve a reportback

```
GET https://www.dosomething.org/api/v1/reportbacks/:id
```

Example request:

```
https://www.dosomething.org/api/v1/reportbacks/1982
```

Example response:

```
{
  data: {
    id: "1982",
    created_at: "1427226250",
    updated_at: "1428442705",
    quantity: 12,
    why_participated: "Nulla vitae elit libero, a pharetra augue.",
    flagged: false,
    reportback_items: {
      total: 2,
      data: [
        {
          id: "1990",
          caption: "Sed posuere consectetur est.",
          uri: "https://www.dosomething.org/api/v1/reportback-items/1990",
          media: {
            uri: "https://www.dosomething.org/sites/default/files/styles/480x480/public/image1990.jpeg",
            type: "image"
          },
          created_at: "1427226250",
          status: "approved"
        },
        {
          id: "1992",
          caption: "Cras justo odio, facilisis.",
          uri: "https://www.dosomething.org/api/v1/reportback-items/1992",
          media: {
            uri: "https://www.dosomething.org/sites/default/files/styles/480x480/public/image1992.jpeg",
            type: "image"
          },
          created_at: "1427226629",
          status: "approved"
        }
      ]
    },
    campaign: {
      id: "58",
      title: "Shelter Pet PR"
    },
    user: {
      id: "128847239"
    }
  }
}
```
