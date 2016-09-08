# Adding And Updating New Phoenix Endpoints

***


1) Create a new resource file in `/lib/modules/dosomething_api/resources` as **example_resource.inc** where "example" is the singular name of the resource.

2) In the **example_resource.inc** file, create the function to define the resource and return the array definition:

```php
<?php

function _example_resource_definition() {
  $example_resource = [];
  $example_resource['examples'] = [
    'operations' => [
      // add operations: index, retrieve, create, delete
    ],

    'actions'  => [
      // add actions performed directly on a resource type
      // NOTE: only works with POST requests
      // e.g. /api/v1/examples/action
    ],

    'targeted_actions' => [
      // add targeted actions performed directly on an individual resource
      // e.g. /api/v1/examples/123/sometargetedaction
    ],

    'relationships' => [
      // convenience method related to an individual resource
      // e.g. /api/v1/examples/123/comments 
      // relationship above is syntactic sugar for /api/v1/comments?example_id=123
    ],
  ];

  return $example_resource;
}

?>
```

Note in the above code, the `examples` array item is the _plural_ form of the resource, and is what the endpoint will be defined as: `/api/v1/examples`.

Also note, that for most of the Phoenix endpoints we try to stay within the basic REST HTTP methods, and try to refrain from using `actions`, `targeted_actions` and `relationships`, but it is not a hard set rule.

All resource endpoints should be the plural form of the resource!

There are more functions that need to be defined in this resource file, but refer to some of the existing resources for further examples. These functions are prefixed with the _singular_ name of the resource: `_example_resource_index()`.

3) With the **example_resource.inc** file created, you need to tell the the DoSomething API module about it so it includes it in the array of available resources, so include the resource file and add it to the function that builds out the available resources array:

```php
 <?php
 // /lib/modules/dosomething_api/dosomething_api.module

 include_once 'resources/example_resource.inc';

 ...

function dosomething_api_services_resources() {

  $resources = [];

  ...

  // add to series of items that build out the array
  $resources += _example_resource_definition();

  return $resources;
}
 
?>
```

4) Clear the cache using `drush cc all`. Everytime you edit the array in the definitions function in the **example_resource.inc** file you need to be sure to clear the Drupal cache, otherwise your changes will not take effect!

5) Profit! (err, Non-profit!)

... More to come on further specifics, but this is a good starting point!


