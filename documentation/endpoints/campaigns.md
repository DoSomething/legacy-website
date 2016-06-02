# Campaigns Endpoint

- [Retrieve A Campaign](#retrieve-a-campaign)

## Retrieve A Campaign

Get data for a specified campaign.

```
GET /api/v1/campaign/:id
```

**Headers**

```javascript
Accept: application/json
Content-Type: application/json
```

**Example Request**

```sh
curl -X GET \
  -H "Content-Type: application/json" \
  -H "Accept: application/json" \
  https://www.dosomething.org/api/v1/campaigns/362
```

**Example Response**

```javascript
// 200 Okay

{
  "data": {
    "id": "362",
    "title": "Comeback Clothes",
    "campaign_runs": {
      "current": {
        "en": {
          "id": "1227"
        }
      },
      "past": [
        
      ]
    },
    "language": {
      "language_code": "en",
      "prefix": "us"
    },
    "translations": {
      "original": "en",
      "en": {
        "language_code": "en",
        "prefix": "us"
      },
      "en-global": {
        "language_code": "en-global",
        "prefix": null
      }
    },
    "tagline": "Recycle old or worn-out clothes to help all the planets.",
    "status": "active",
    "type": "campaign",
    "created_at": "1393518858",
    "updated_at": "1461690475",
    "time_commitment": 5,
    "cover_image": {
      "default": {
        "uri": "http://dev.dosomething.org:8888/sites/default/files/styles/300x300/public/ComebackClothes_hero_square.jpg?itok=tWoJlXKl",
        "sizes": {
          "landscape": {
            "uri": "http://dev.dosomething.org:8888/sites/default/files/styles/1440x810/public/ComebackClothes_hero_landscape.jpg?itok=urtK3cfp"
          },
          "square": {
            "uri": "http://dev.dosomething.org:8888/sites/default/files/styles/300x300/public/ComebackClothes_hero_square.jpg?itok=tWoJlXKl"
          }
        },
        "type": "image",
        "dark_background": false
      },
      "alternate": null
    },
    "staff_pick": true,
    "competition": false,
    "facts": {
      "problem": "11.1 million tons of fabric that could be recycled ends up in landfills every year. That's the equivalent of over 70 billion t-shirts.",
      "solution": null,
      "sources": [
        {
          "formatted": "<p>\"Textiles.\" United States Environmental Protection Agency. Accessed February 24, 2014. http://www.epa.gov/osw/conserve/materials/textiles.htm</p>\n"
        }
      ]
    },
    "solutions": {
      "copy": {
        "raw": "Instead of trashing old clothes, give them a second life by recycling them. You’ll save water, energy, and landfill space.",
        "formatted": "<p>Instead of trashing old clothes, give them a second life by recycling them. You’ll save water, energy, and landfill space.</p>\n"
      },
      "support_copy": {
        "raw": "Run a drive at your school to collect recycled clothes and drop them off at your local H&M.",
        "formatted": "<p>Run a drive at your school to collect recycled clothes and drop them off at your local H&amp;M.</p>\n"
      }
    },
    "pre_step": {
      "header": "Run Your Drive!",
      "copy": {
        "raw": "If you’re lucky, you’ll see more mustard-, blood-, and mystery-liquid-stained stuff than ever before! Gross! Hooray!",
        "formatted": "<p>If you’re lucky, you’ll see more mustard-, blood-, and mystery-liquid-stained stuff than ever before! Gross! Hooray!</p>\n"
      }
    },
    "latest_news": {
      "latest_news": null
    },
    "causes": {
      "primary": {
        "id": "4",
        "name": "environment"
      },
      "secondary": [
        {
          "id": "4",
          "name": "environment"
        }
      ]
    },
    "action_types": {
      "primary": {
        "id": "7",
        "name": "donate something"
      },
      "secondary": [
        {
          "id": "7",
          "name": "donate something"
        },
        {
          "id": "11",
          "name": "host an event"
        },
        {
          "id": "8",
          "name": "improve a space"
        }
      ]
    },
    "issue": {
      "id": "347",
      "name": "recycling"
    },
    "tags": [
      {
        "id": "48",
        "name": "trash"
      },
      {
        "id": "348",
        "name": "recycling"
      },
      {
        "id": "349",
        "name": "clothes"
      },
      {
        "id": "350",
        "name": "h&m"
      },
      {
        "id": "102",
        "name": "drive"
      },
      {
        "id": "49",
        "name": "earth"
      },
      {
        "id": "351",
        "name": "planet"
      },
      {
        "id": "97",
        "name": "environment"
      },
      {
        "id": "352",
        "name": "eco"
      },
      {
        "id": "366",
        "name": "collection"
      },
      {
        "id": "668",
        "name": "music"
      }
    ],
    "timing": {
      "high_season": {
        "start": "2015-07-18T00:00:00+0000",
        "end": "2015-07-25T00:00:00+0000"
      },
      "low_season": null
    },
    "services": {
      "mobile_commons": {
        "opt_in_path_id": "165501",
        "friends_opt_in_path_id": null
      },
      "mailchimp": {
        "grouping_id": null,
        "group_name": null
      }
    },
    "affiliates": {
      "partners": [
        {
          "name": "H&M",
          "sponsor": true,
          "copy": {
            "raw": "H&M was the first fast fashion company, and now they’re leading the movement toward a more sustainable fashion future. We <3 them and they <3 the earth. At H&M, sustainability is a word of action – something they do rather than something they simply say. It is an ongoing process that requires determination, passion and teamwork.\r\n\r\nH&M wants to make more sustainable choices in fashion affordable and desirable to as many people as possible.\r\n\r\nWe believe that partnering with a sustainably minded company can create real and long-term changes. With our 2.5 million members and H&M's millions of customers, we can extend this impact even further – from improving the livelihood of a cotton farmer to how people everywhere dispose of their worn-out clothing.\r\n\r\nLearn more about <a href=”http://about.hm.com/en/About/Sustainability/HMConscious/Aboutconscious.html>H&M’s sustainability initiatives here.</a>",
            "formatted": "<p>H&amp;M was the first fast fashion company, and now they’re leading the movement toward a more sustainable fashion future. We &lt;3 them and they &lt;3 the earth. At H&amp;M, sustainability is a word of action – something they do rather than something they simply say. It is an ongoing process that requires determination, passion and teamwork.</p>\n\n<p>H&amp;M wants to make more sustainable choices in fashion affordable and desirable to as many people as possible.</p>\n\n<p>We believe that partnering with a sustainably minded company can create real and long-term changes. With our 2.5 million members and H&amp;M's millions of customers, we can extend this impact even further – from improving the livelihood of a cotton farmer to how people everywhere dispose of their worn-out clothing.</p>\n\n<p>Learn more about <a href=\"//about.hm.com/en/About/Sustainability/HMConscious/Aboutconscious.html\">H&amp;M’s sustainability initiatives here.</a></p>\n"
          },
          "uri": "http://www.hm.com/",
          "media": {
            "uri": "http://dev.dosomething.org:8888/sites/default/files/styles/wmax-423px/public/partners/hm-logo.png?itok=hf89RS8a",
            "type": "image"
          }
        }
      ]
    },
    "reportback_info": {
      "copy": "Submit your photo before June 20 to qualify for the scholarship.",
      "confirmation_message": "Going green is always in style! Thanks for helping the Earth.",
      "noun": "Items",
      "verb": "Recycled"
    },
    "uri": "http://dev.dosomething.org:8888/api/v1/campaigns/362"
  }
}
```

## Campaign reportback

Creates or updates a User Reportback for the given Campaign nid.

**POST** `https://www.dosomething.org/api/v1/campaigns/[nid]/reportback`

Must be authenticated to post.

  - **uid**: (int).
    The user uid reporting back.  If not included, the uid of the current user will be used.
  - **nid**: (int) required.
    The node nid the user is reporting back to.
  - **quantity**: (int) required.
    The number of reportback nouns verbed.
  - **why_participated**: (string) required.
    The reason why the user participated.
  - **file_url**: (string) required if `file` is not provided.
    An image URL for the reportback.
  - **file**: (string) required if `file_url` is not provided.
    Base64 encoded file string to save.
  - **filename**: (string) required if `file` is provided.
    Necessary for Drupal File API save (see `dosomething_reportback_get_file_dest`).
  - **caption**: (string).
    Corresponding caption for the reportback image.
  - **source**: (string).
    Where the reportback file was submitted from.

Response: The reportback rbid if success, `FALSE` if not.

Example request:
````
curl https://www.dosomething.org/api/v1/campaigns/23/reportback -X POST 
--header "Content-type: application/json" 
--header "Accept: application/json" 
--header "X-CSRF-Token: G136HF5yB5ZZawvrsOfU4gw0poUOaQygPrsJlaFakMU" 
--header "Cookie:SESSd57f2aef87e6d4352ce5db4659184fa7=mKI5_yfoXYBz3r4o95utui4fwBV_lUO1JNN1nEVsPRg" 
-d '{
  "quantity": 30,
  "uid": 1702889,
  "file_url": "http://voldemortwearsarmani.files.wordpress.com/2013/01/batman-chronicles.jpg",
  "why_participated": "Test from API",
  "caption": "API Testing!",
  "source": "Mobile App"
}'
````

Example response:
````
["127"]
````