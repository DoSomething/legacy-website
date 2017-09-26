# Campaigns

## Retrieve all campaigns

```
GET https://www.dosomething.org/api/v1/campaigns
```

Note: Only campaigns with a campaign type of `campaign` are returned (e.g. `sms_game` campaigns [are filtered](https://github.com/DoSomething/LetsDoThis-iOS/issues/813#issuecomment-189545768))
### Optional Query Parameters

- **ids** _(string|csv)_
  - Specify the campaign(s) to return
  - ex: `/campaigns?ids=123,456,789`
- **count** _(default is 25)_
  - Set the number of campaigns to return in a single response
  - ex: `/campaigns?count=25`
- **page** _(integer)_
  - For pagination, specify page of campaigns to return in the response
  - ex: `/campaigns?page=2`
- **staff_pick** _(boolean)_
  - If set to `true`, will only return _staff pick_ campaigns
  - ex: `/campaigns?staff_pick=true`
- **term_ids** _(string|csv)_
  - Return only campaigns that are tagged with the term IDs specified
  - ex: `/campaigns?term_ids=123,456,789`
- **random** _(boolean)_
  - If set to `true`, will return campaigns in random order
  - ex: `/campaigns?random=true`
- **cache** _(boolean)_
  - Defaults to `true`
  - If set to `false` will not cache request and if already cached, it will be removed from cache
  - ex: `/campaigns?cache=false`


## Retrieve a campaign

```
GET https://www.dosomething.org/api/v1/campaigns/:id
```

- **id** _(int)_ [Required]
 - The id of the campaign node to retrieve data for.

Example request:
```
https://www.dosomething.org/api/v1/campaign/1247
```

Example response:
```
{
  data: {
    id: "362",
    title: "Comeback Clothes",
    campaign_runs: {
      current: {
        en: {
          id: "1227",
          "start_date":"2015-10-19 00:00:00"
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
    tagline: "Recycle old or worn-out clothes to help all the planets.",
    created_at: "1393518858",
    updated_at: "1452893294",
    status: "closed",
    time_commitment: 5,
    cover_image: {
      default: {
        uri: "http://dev.dosomething.org:8888/sites/default/files/styles/300x300/public/ComebackClothes_hero_square.jpg?itok=4FFah0EJ",
        sizes: {
          landscape: {
            uri: "http://dev.dosomething.org:8888/sites/default/files/styles/1440x810/public/ComebackClothes_hero_landscape.jpg?itok=f9LusEHG"
          },
          square: {
            uri: "http://dev.dosomething.org:8888/sites/default/files/styles/300x300/public/ComebackClothes_hero_square.jpg?itok=4FFah0EJ"
          }
        },
        type: "image",
        dark_background: false
      },
      alternate: null
    },
    staff_pick: true,
    competition: true,
    facts: {
      problem: "11.1 million tons of fabric that could be recycled ends up in landfills every year. That's the equivalent of over 70 billion t-shirts.",
      solution: null,
      sources: [
        {
          formatted: "<p>"Textiles." United States Environmental Protection Agency. Accessed February 24, 2014. http://www.epa.gov/osw/conserve/materials/textiles.htm</p> "
        }
      ]
    },
    solutions: {
      copy: {
        raw: "Instead of trashing old clothes, give them a second life by recycling them. You’ll save water, energy, and landfill space.",
        formatted: "<p>Instead of trashing old clothes, give them a second life by recycling them. You’ll save water, energy, and landfill space.</p> "
      },
      support_copy: {
        raw: "Run a drive at your school to collect recycled clothes and drop them off at your local H&M.",
        formatted: "<p>Run a drive at your school to collect recycled clothes and drop them off at your local H&amp;M.</p> "
      }
    },
    pre_step: {
      header: "Run Your Drive!",
      copy: {
        raw: "If you’re lucky, you’ll see more mustard-, blood-, and mystery-liquid-stained stuff than ever before! Gross! Hooray!",
        formatted: "<p>If you’re lucky, you’ll see more mustard-, blood-, and mystery-liquid-stained stuff than ever before! Gross! Hooray!</p> "
      }
    },
    latest_news: {
      latest_news: null
    },
    causes: {
      primary: {
        id: "4",
        name: "environment"
      },
      secondary: [
        {
          id: "4",
          name: "environment"
        }
      ]
    },
    action_types: {
      primary: {
        id: "7",
        name: "donate something"
      },
      secondary: [
        {
          id: "7",
          name: "donate something"
        },
        {
          id: "11",
          name: "host an event"
        },
        {
        id: "8",
        name: "improve a space"
        }
      ]
    },
    issue: {
      id: "347",
      name: "recycling"
    },
    tags: [
      {
        id: "48",
        name: "trash"
      },
      {
        id: "348",
        name: "recycling"
      },
      {
        id: "349",
        name: "clothes"
      },
      {
        id: "350",
        name: "h&m"
      },
      {
        id: "102",
        name: "drive"
      },
      {
        id: "49",
        name: "earth"
      },
      {
        id: "351",
        name: "planet"
      },
      {
        id: "97",
        name: "environment"
      },
      {
        id: "352",
        name: "eco"
      },
      {
        id: "366",
        name: "collection"
      },
      {
        id: "668",
        name: "music"
      }
    ],
    timing: {
      high_season: {
        start: "2015-07-18T00:00:00+0000",
        end: "2015-07-25T00:00:00+0000"
      },
      low_season: null
    },
    services: {
      mobile_commons: {
        opt_in_path_id: "165501",
        friends_opt_in_path_id: null
      },
      mailchimp: {
        grouping_id: null,
        group_name: null
      }
    },
    reportback_info: {
      copy: "Submit your photo before June 20 to qualify for the scholarship.",
      confirmation_message: "Going green is always in style! Thanks for helping the Earth.",
      noun: "Items",
      verb: "Recycled"
    },
    uri: "http://dev.dosomething.org:8888/api/v1/campaigns/362",
    magic_link_copy: "Here's why you should click this magic link"
  }
}
```


## Retrieve a non-transformed campaign

This uses Drupal Services `content` endpoint and should only be used in legacy requests.

```
GET https://www.dosomething.org/api/v1/content/:nid
```

**nid** (int) Required. The Node nid to retrieve content for.

Example request:
```
curl https://www.dosomething.org/api/v1/content/5140 \
 -H "Accept: application/json"
```



## Campaign signup

Creates a User Signup for the given Campaign nid if a Signup does not exist.

```
POST https://www.dosomething.org/api/v1/campaigns/[nid]/signup
```

Must be authenticated to post.

  - **northstar_id**: (string).
    The Northstar ID of the user to create a signup for.
  - **source**: (string) required.
    The signup source, e.g. `iphone`, `android`

Example request:
````
curl https://www.dosomething.org/api/v1/campaigns/23/signup -X POST
--header "Content-type: application/json"
--header "Accept: application/json"
--header "X-CSRF-Token: G136HF5yB5ZZawvrsOfU4gw0poUOaQygPrsJlaFakMU"
--header "Cookie:SESSd57f2aef87e6d4352ce5db4659184fa7=mKI5_yfoXYBz3r4o95utui4fwBV_lUO1JNN1nEVsPRg"
-d '{
  "northstar_id": "5543dfd6469c64ec7d8b46b3",
  "source": "sms"
}'
````

Response: Signup sid, if success.

````
[
    "1307"
]
````

## Campaign reportback

Creates or updates a User Reportback for the given Campaign nid.

```
POST https://www.dosomething.org/api/v1/campaigns/[nid]/reportback
```

Must be authenticated to post.

  - **northstar_id**: (string).
    The Northstar ID of the user to create a reportback for.
  - **nid**: (int) required.
    The node nid the user is reporting back to.
  - **quantity**: (int) required.
    The number of reportback nouns verbed.
  - **why_participated**: (string) required.
    The reason why the user participated.
  - **file_url**: (string) required if `file` is not provided and a new reportback is being created.
    An image URL for the reportback.
  - **file**: (string) required if `file_url` is not provided and a new reportback is being created.
    Base64 encoded file string to save.
  - **filename**: (string) required if `file` is provided.
    Necessary for Drupal File API save (see `dosomething_reportback_get_file_dest`).
  - **caption**: (string).
    Corresponding caption for the reportback image.
  - **source**: (string).
    Where the reportback file was submitted from.
  - **remote_addr**: (string). optional
    Remote address the reportback file was submitted from.

Response: The reportback rbid if success, `FALSE` if not.

Example request:
```
curl https://www.dosomething.org/api/v1/campaigns/23/reportback -X POST
--header "Content-type: application/json"
--header "Accept: application/json"
--header "X-CSRF-Token: G136HF5yB5ZZawvrsOfU4gw0poUOaQygPrsJlaFakMU"
--header "Cookie:SESSd57f2aef87e6d4352ce5db4659184fa7=mKI5_yfoXYBz3r4o95utui4fwBV_lUO1JNN1nEVsPRg"
-d '{
  "quantity": 30,
  "northstar_id": "5543dfd6469c64ec7d8b46b3",
  "file_url": "http://voldemortwearsarmani.files.wordpress.com/2013/01/batman-chronicles.jpg",
  "why_participated": "Test from API",
  "caption": "API Testing!",
  "source": "Mobile App"
}'
```

Example response:
```
["127"]
```
