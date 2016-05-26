# Phoenix API

This is the **Phoenix API** for working with the [DoSomething.org](https://dosomething.org) platform.

## Authentication
The Services API endpoints use Drupal sessions to authenticate and authorize requests.

## Endpoints 

#### Users
Endpoint                                       | Functionality                                           
---------------------------------------------- | --------------------------------------------------------
`POST /api/v1/users`                           | [Create a User](endpoints/users.md#create-a-user)
`GET /api/v1/users`                            | [Retrieve a User](endpoints/users.md#retrieve-a-user) 
`POST /api/v1/get_member_count/`               | [Get Member Count](endpoints/users.md#get-member-count)
`GET /api/v1/users/current/activity?nid={nid}` | [Get User Activity](endpoints/users.md#get-user-activity)
`POST /api/v1/users/{uid}/password_reset_url`  | [Create Password Reset URL](endpoints/users.md#create-password-reset-url)
