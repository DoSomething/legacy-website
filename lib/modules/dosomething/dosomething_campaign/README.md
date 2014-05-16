# DoSomething Campaign

This module defines the Campaign node type and provides related functionality.

* The `dosomething_user` and `dosomething_signup` modules handle the actual
campaign signups.
* The `dosomething_reportback` module handles creating and
updating user reportbacks for the campaign.

## Campaign Types

There are two Campaign types  currently available:

* Campaign
* SMS Game

This is defined by the value saved in a Campaign node's `field_campaign_type`.
 

## View Modes

We make use of entity view modes in order to display campaigns differently based on
user signup status, and the Campaign's Campaign Type.

An advantage of this approach is that the different campaign types share the same node type and its corresponding fields, permissions, etc. which means less features and modules to maintain.

A disadvantage of this approach is that the entity view modes are available to ALL 
node types, so you'll notice that the various content types like Image, Static Content, Fact Page, etc.
all have the `sms_game` and `pitch` view_modes exported in their Features definitions.  We never 
actually use the "Manage display" node functionality. so it's not such a bad tradeoff.

### Pitch Page

The pitch page is a custom Entity view mode, defined in `dosomething_campaign_entity_info_alter`.

It is displayed when a user is viewing a campaign node where Campaign Type == `campaign` and when 
either is true:

 * An anonymous users is viewing the campaign node.
     *   For anonymous users, the signup button opens up a login/register modal.  Upon
signing in, the user will be signed up for the campaign, and directed to the
action page.

 * An authenticated user has not signed up for the campaign node
     *  For auth users, the signup button will up the user and direct
the user to the action page.


A staff user is able to view the pitch page by navigating to `node/[nid]/pitch`.


### Action Page

The action page is an internal term used by the campaigns team, technically it's implemented as just the "full" view mode of the Campaign node type where Campaign Type == `campaign`.

It is displayed when authenticated users are viewing a campaign node and have signed up for the campaign.

A staff user will view the action page by default when viewing a campaign, regardless of signup status.
 See `dosomething_campaign_entity_view_mode_alter().`

The Action page includes a user reportback form, where the user can reportback
on the campaign. Upon submitting, the user is directed to the confirmation page.

If a user who has reported back navigates to the campaign again, they are able
to update their reportback submission.

### SMS Game

The SMS Game is also a custom Entity view mode defined in `dosomething_campaign_entity_info_alter`.
This view mode is displayed when the Campaign Type == `sms_game`.

The SMS Game campaign type does not require all of the various fields that a standard
Campaign does, so field groups are hidden from the Campaign node form upon selecting
"SMS Game".  This is implemented via Javascript added in `dosomething_campaign_form_campaign_node_form_alter`. 

The SMS Game is available to anonymous users; you do not have to sign in to submit the Alpha/Beta Signup form which is rendered on a SMS Game.


## Confirmation Page

The confirmation page is implemented via a menu hook and page callback, with path
`node/[nid]/confirmation`.

The confirmation page displays 3 recommended campaigns for the user.  This is
determined by first finding published campaigns which are staff picks, that the
user has not signed up for.

If there are less than 3 staff picks that the user hasn't signed up for, the
confirmation page will also display published campaigns which share the same
Primary Cause, for which the user has not signed up for.

### Campaigns

On campaigns, the confirmation page is displayed after a user submits the reportback form.  The user is only able
to access the confirmation page if they have reported back for the campaign.  A
staff user is able to view the confirmation page at any time.

### SMS Game

For SMS Games, the confirmation page is displayed after a user submits the Alpha/Beta
Signup form.  Because anonymous users can submit the form, anonymous users can access the confirmation page of a SMS Game.
