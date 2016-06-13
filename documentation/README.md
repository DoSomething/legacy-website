# Phoenix API

This is the **Phoenix API** for working with the [DoSomething.org](https://dosomething.org) platform.

## Authentication
The Services API endpoints use Drupal sessions to authenticate and authorize requests.

## Endpoints

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
`GET /api/v1/signups`                          | [Retrieve all signups](endpoints/campaigns.md#retrieve-all-signups)
`GET /api/v1/signups/:id`                      | [Retrieve a signup](endpoints/campaigns.md#retrieve-a-signup)

#### Users
Endpoint                                       | Functionality                                           
---------------------------------------------- | --------------------------------------------------------
`POST /api/v1/users`                           | [Create a User](endpoints/users.md#create-a-user)
`GET /api/v1/users`                            | [Retrieve a User](endpoints/users.md#retrieve-a-user)
`POST /api/v1/get_member_count/`               | [Get Member Count](endpoints/users.md#get-member-count)
`GET /api/v1/users/current/activity?nid={nid}` | [Get User Activity](endpoints/users.md#get-user-activity)
`POST /api/v1/users/{uid}/password_reset_url`  | [Create Password Reset URL](endpoints/users.md#create-password-reset-url)
