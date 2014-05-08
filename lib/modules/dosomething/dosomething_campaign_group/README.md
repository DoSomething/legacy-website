# DoSomething Campaign Group

This module defines the Grouped Campaign content type (machine name `campaign_group`).

A Grouped Campaign contains an entityreference field, `field_campaigns`, which 
determines which Campaign nodes belong to the Grouped Campaign.

## Signups

The `field_display_signup_form` field configures whether or not to display a 
Signup form on the Grouped Campaign node template.

This Signup form will store a signup for the Grouped Campaign nid.  A Grouped
Campaign may be configured to subscribe the user to third-party services such as
Mailchimp and Mobilecommons via the DoSomething Signup admin form.

When a user signs up for a Campaign within the Grouped Campaign, a Signup will 
also be created for the Grouped Campaign the Campaign belongs to.  See `dosomething_signup_entity_insert`. 
