# DoSomething Settings

This module contains exported settings for various system modules such as 
Filter, File Entity, and Services. 

## Services

The `drupalapi` endpoint is defined at `api/v1`.  It is currently configured 
to not use session information, so all requests will be done as an anonymous user.

### Retrieve a campaign

Currently we are only using the Node Retrieve resource, at alias `content`.

**GET** `https://www.dosomething.org/api/v1/content/:nid`

**nid** (int) Required. The Node nid to retrieve content for. 

The `dosomething_settings_services_request_postprocess_alter` function is 
postprocessing the Node resource's output to only return content for a given 
Campaign node.  This function modifies the output to use the Campaign class, 
as defined in `dosomething_campaign_load`.

If a non-campaign Node nid is passed, the response returned will be `false`.

Since all requests are done as an anonymous user, the Node resource will 
use our user permissions and not return unpublished campaigns for anonymous 
users: `["Access denied for user anonymous"]`
