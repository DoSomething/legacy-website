# Phoenix API

This is the **Phoenix API** for working with the [DoSomething.org](https://dosomething.org) platform.

## Authentication
The Services API endpoints use Drupal sessions to authenticate and authorize requests.

## Endpoints

#### Authentication
Endpoint                                       | Functionality                                           
---------------------------------------------- | --------------------------------------------------------
`POST /api/v1/auth/login`                      | [Log in](endpoints/auth.md#log-in)
`POST /api/v1/auth/logout`                     | [Log out](endpoints/auth.md#log-out)
`GET /api/v1/auth/token`                       | [Get auth token](endpoints/auth.md#retrieve-a-token)


#### Campaigns
Endpoint                                       | Functionality                                           
---------------------------------------------- | --------------------------------------------------------
`GET /api/v1/campaigns`                        | [Retrieve all campaigns](endpoints/campaigns.md#retrieve-all-campaigns)
`GET /api/v1/campaign/:id`                     | [Retrieve a Campaign](endpoints/campaigns.md#retrieve-a-campaign)
`POST /api/v1/campaign/:id/signup`             | [Signup to a Campaign](endpoints/campaigns.md#campaign-signup)
`POST /api/v1/campaign/:id/reportback`         | [Reportback to a Campaign](endpoints/campaigns.md#campaign-reportback)

### Content
Endpoint                                       | Functionality                                           
---------------------------------------------- | --------------------------------------------------------
`GET /api/v1/content/:id`                      | [Retrieve a non-transformed campaign](endpoints/campaigns.md#retrieve-a-non-transformed-campaign)

#### Signups
Endpoint                                       | Functionality                                           
---------------------------------------------- | --------------------------------------------------------
`GET /api/v1/signups`                          | [Retrieve all signups](endpoints/signups.md#retrieve-all-signups)
`GET /api/v1/signups/:id`                      | [Retrieve a signup](endpoints/signups.md#retrieve-a-signup)

#### Kudos
Endpoint                                       | Functionality                                           
---------------------------------------------- | --------------------------------------------------------
`POST /api/v1/kudos`                           | [Create a kudos](endpoints/kudos.md#create-a-kudos)
`GET /api/v1/kudos`                            | [Retrieve all kudos](endpoints/kudos.md#retrieve-all-kudos)
`GET /api/v1/kudos/:id`                        | [Retrieve a kudos](endpoints/kudos.md#retrieve-a-kudos)

#### Reportbacks
Endpoint                                       | Functionality                                           
---------------------------------------------- | --------------------------------------------------------
`GET /api/v1/reportbacks`                      | [Retrieve all reportbacks](endpoints/reportbacks.md#retrieve-all-reportbacks)
`GET /api/v1/reportbacks/:id`                  | [Retrieve a reportback](endpoints/reportbacks.md#retrieve-a-reportback)

#### Reportback Items
Endpoint                                       | Functionality                                           
---------------------------------------------- | --------------------------------------------------------
`GET /api/v1/reportback-items`                 | [Retrieve all reportback items](endpoints/reportback-items.md#retrieve-all-reportback-items)
`GET /api/v1/reportback-items/:id`             | [Retrieve a reportback item](endpoints/reportback-items.md#retrieve-a-reportback-item)
`POST /api/v1/reportback-files/:id`            | [Review a reportback file](endpoints/reportback-items.md#review-a-reportback-file)

#### System
Endpoint                                       | Functionality                                           
---------------------------------------------- | --------------------------------------------------------
`POST /api/v1/system/connect`                  | [Connection status](endpoints/system.md#connection-status)
`GET /api/v1/system/set_variable`              | [Set a variable](endpoints/system.md#set-a-variable)

#### Terms
Endpoint                                       | Functionality                                           
---------------------------------------------- | --------------------------------------------------------
`GET /api/v1/terms`                            | [Retrieve all terms](endpoints/terms.md#retrieve-all-terms)
`GET /api/v1/taxonomy_term/:id`                | [Retrieve a term](endpoints/terms.md#retrieve-a-term)


#### Users
Endpoint                                       | Functionality                                           
---------------------------------------------- | --------------------------------------------------------
`POST /api/v1/users`                           | [Create a User](endpoints/users.md#create-a-user)
`GET /api/v1/users`                            | [Retrieve a User](endpoints/users.md#retrieve-a-user)
`POST /api/v1/get_member_count/`               | [Get Member Count](endpoints/users.md#get-member-count)
`GET /api/v1/users/current/activity?nid={nid}` | [Get User Activity](endpoints/users.md#get-user-activity)
`POST /api/v1/users/{uid}/password_reset_url`  | [Create Password Reset URL](endpoints/users.md#create-password-reset-url)


#### Magicks
Endpoint                                       | Functionality                                           
---------------------------------------------- | --------------------------------------------------------
`GET /api/v1/magicks?action=action_name`       | [Cast Magick Action](endpoints/magicks.md#cast-magick-action)

