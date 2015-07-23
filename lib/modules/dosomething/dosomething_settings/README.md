# DoSomething Settings

This module contains exported settings for various system modules such as 
Filter, File Entity, and Services. 

## Services

See https://github.com/DoSomething/phoenix/wiki/API for usage.

The API is provided by the `drupalapi` Services endpoint, defined at `api/v1`.


### Users

User authentication is handled via Services User resources:
* login
* logout

And the System resources:
* connect


### Nodes

Currently we are only using the Node Retrieve resource, at alias `content`.

The `dosomething_settings_services_request_postprocess_alter` function is 
postprocessing the Node resource's output to only return content for a given 
Campaign node.  This function modifies the output to use the Campaign class, 
as defined in `dosomething_campaign_load`.

If a non-campaign Node nid is passed, the response returned will be `false`.

The Node resource will use our user permissions and not return unpublished 
campaigns for anonymous or authenticated users:

````
["Access denied for user anonymous"]
````

If an editor or administrator were logged in via Services and accessed an 
unpublished node, it would be returned. 
