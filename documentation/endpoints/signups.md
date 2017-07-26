## Retrieve all signups

```
GET https://www.dosomething.org/api/v1/signups
```

Returns campaign activity, including signups and reportbacks.

### Optional query parameters

- **user** _(string|csv)_
 - Comma separated list of user IDs to get signups for.
 - eg: `/signups?user=5543dfd6469c64ec7d8b46b3,5554eac1a59dbf117e8b4567`
- **campaigns** _(string|csv)_
 - Comma separated list of campaign IDs to get signups for.
 - eg: `/signups?campaigns=362,1172`
- **count** _(integer)_
 - The number of signups to retrieve
 - eg: `/signups?count=5`
- **page** _(integer)_
 - For pagination, specify page of signups to return in the response
 - eg: `/signups?page=3`
- **competition** _(bool)_
 - Only return competition signups & order by reportback quantity.
 - eg: `/signups?competition=true`
 - NOTE: this filter is only available when Rogue is turned OFF
- **runs** _(string|csv)_
 - Comma separated list of campaign run ids to get signups
 - eg: `/signups?runs=6737`


Example request:

```
http://dev.dosomething.org:8888/api/v1/signups?user=98&campaigns=1173
```

Example response:
```
{
  meta: {
    pagination: {
      total: 1,
      per_page: 25,
      current_page: 1,
      total_pages: 1,
      links: {
        prev_uri: null,
        next_uri: null
      }
    }
  },
  data: [
    {
      id: "243",
      created_at: "1400103603",
      campaign_run: {
        id: "1816",
        current: true
      },
      uri: "http://dev.dosomething.org:8888/api/v1/signups/243",
      campaign: {
        id: "1173",
        title: "Thumb Wars",
        campaign_runs: {
          current: {
            en: {
              id: "1816"
            },
            en-global: {
              id: "1816"
            }
          },
          past: [ ]
        },
        language: {
          language_code: "en",
          prefix: "us"
        },
        translations: {
          original: "en",
          en: {
            language_code: "en",
            prefix: "us"
          },
          en-global: {
            language_code: "en-global",
            prefix: null
          }
        },
        tagline: "Send friends Thumb Socks to remind them not to text and drive.",
        status: "active",
        type: "campaign",
        reportback_info: {
          copy: "Send us a shot of your friend rockin' their Socks!",
          confirmation_message: "Thumbs up, Thumb Warrior! Thanks for keeping your friends -- and the streets -- safe.",
          noun: "Thumb Socks",
          verb: "shared"
        }
      },
      reportback: {
        id: "75",
        created_at: "1400106458",
        updated_at: "1435775063",
        quantity: 12,
        uri: "http://dev.dosomething.org:8888/api/v1/reportbacks/75",
        why_participated: "This is just a test",
        flagged: false,
        reportback_items: {
          total: 5,
          data: [
            {
              id: "498",
              status: "approved",
              caption: "DoSomething? Just did!",
              uri: "http://dev.dosomething.org:8888/api/v1/reportback-items/498",
              media: {
                uri: "http://dev.dosomething.org:8888/sites/default/files/styles/480x480/public/reportbacks/1173/uid_98-nid_1173-0.jpg?itok=4fGl_sNv",
                type: "image"
              },
              created_at: "1402439166",
              kudos: {
                data: [ ]
              }
            },
            {
              id: "499",
              status: "approved",
              caption: "DoSomething? Just did!",
              uri: "http://dev.dosomething.org:8888/api/v1/reportback-items/499",
              media: {
                uri: "http://dev.dosomething.org:8888/sites/default/files/styles/480x480/public/reportbacks/1173/uid_98-nid_1173-1.jpg?itok=KMfogXPn",
type: "image"
              },
              created_at: "1402439166",
              kudos: {
                data: [ ]
              }
            }
          ]
        }
      }
    }
  ]
}
```
## Retrieve a signup

```
GET https://www.dosomething.org/api/v1/signups/:sid
```

Returns campaign activity, including signups and reportbacks.

Example request:
```
http://dev.dosomething.org:8888/api/v1/signups/42
```

Example response:
```
{
  data: {
    id: "42",
    created_at: "1394567434",
    campaign_run: {
      id: "0",
      current: false
    },
    uri: "http://dev.dosomething.org:8888/api/v1/signups/42",
    campaign: {
      id: "1173",
      title: "Thumb Wars",
      campaign_runs: {
        current: {
          en: {
            id: "1816"
          },
          en-global: {
            id: "1816"
          }
        },
          past: [ ]
        },
        language: {
          language_code: "en",
          prefix: "us"
        },
        translations: {
          original: "en",
          en: {
            language_code: "en",
            prefix: "us"
          },
          en-global: {
            language_code: "en-global",
            prefix: null
          }
        },
        tagline: "Send friends Thumb Socks to remind them not to text and drive.",
        status: "active",
        type: "campaign",
        reportback_info: {
          copy: "Send us a shot of your friend rockin' their Socks!",
          confirmation_message: "Thumbs up, Thumb Warrior! Thanks for keeping your friends -- and the streets -- safe.",
          noun: "Thumb Socks",
          verb: "shared"
        }
      },
      reportback: {
        id: "75",
        created_at: "1400106458",
        updated_at: "1435775063",
        quantity: 12,
        uri: "http://dev.dosomething.org:8888/api/v1/reportbacks/75",
        why_participated: "This is just a test",
        flagged: false,
        reportback_items: {
          total: 5,
          data: [
            {
              id: "498",
              status: "approved",
              caption: "DoSomething? Just did!",
              uri: "http://dev.dosomething.org:8888/api/v1/reportback-items/498",
              media: {
                uri: "http://dev.dosomething.org:8888/sites/default/files/styles/480x480/public/reportbacks/1173/uid_98-nid_1173-0.jpg?itok=4fGl_sNv",
                type: "image"
              },
              created_at: "1402439166",
              kudos: {
                data: [ ]
              }
            },
          ]
        }
      }
    }
  ]
}
```
