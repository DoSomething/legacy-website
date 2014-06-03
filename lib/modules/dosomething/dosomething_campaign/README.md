# DoSomething Campaign

This module defines the Campaign node type and provides related functionality.

* The `dosomething_user` and `dosomething_signup` modules handle the actual
campaign signups.
* The `dosomething_reportback` module handles creating and
updating user reportbacks for the campaign.

## Campaign Types

There are two Campaign types currently available:

* Campaign
* SMS Game

This is defined by the value saved in a Campaign node's `field_campaign_type`.
 

### Campaign

A Campaign refers to a Campaign node where Campaign Type == 'campaign'.

A live Campaign has two different displays: a Pitch Page and an Action Page.

#### Pitch Page

A pitch page renders the Campaign node in `node--campaign--pitch.tpl.php`. 
@see `dosomething_campaign_preprocess_node`.

The logic for when it is displayed is defined in `dosomething_campaign_is_pitch_page($node)`.

The pitch page will display when either is true:

 * An anonymous users is viewing the campaign node.
     *   For anonymous users, the signup button opens up a login/register modal.  Upon
signing in, the user will be signed up for the campaign, and directed to the
action page.

 * An authenticated user has not signed up for the campaign node
     *  For auth users, the signup button will up the user and direct
the user to the action page.


A staff user is able to view the pitch page by navigating to `node/[nid]/pitch`.


#### Action Page

The action page is an internal term used by the campaigns team, technically it's implemented as just the "full" view mode of a Campaign in `node--campaign.tpl.php`.

It is displayed when authenticated users are viewing a campaign node and have signed up for the campaign.

A staff user will view the action page by default when viewing a campaign, regardless 
of signup status.  This is implemented via `dosomething_campaign_is_pitch_page().`

The Action page includes a user reportback form, where the user can reportback
on the campaign. Upon submitting, the user is directed to the confirmation page.

If a user who has reported back navigates to the campaign again, they are able
to update their reportback submission.


### SMS Game

A SMS Game Campaign node is rendered in `node--campaign--sms-game.tpl.php`.
@see `dosomething_campaign_preprocess_node`.

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

### Campaign Confirmation Page

On campaigns, the confirmation page is displayed after a user submits the reportback form.  The user is only able
to access the confirmation page if they have reported back for the campaign.  A
staff user is able to view the confirmation page at any time.

### SMS Game Confirmation Page

For SMS Games, the confirmation page is displayed after a user submits the Alpha/Beta
Signup form.  Because anonymous users can submit the form, anonymous users can access the confirmation page of a SMS Game.



## States

A Campaign node (regardless of Campaign type) has two states:

### Live

When a campaign node is live, users can signup and reportback. The campaigns display
in the Finder.

### Closed

When a campaign node is closed, users can no longer signup or reportback. 

A closed campaign node is rendered in `node--campaign--closed.tpl.php`.  The 
function `dosomething_campaign_is_closed($node)` determines when a campaign is
closed and when to use this template.

The content of the closed state is stored in the campaign node's related closed
Campaign Run node.

A closed campaign renders the same display for both anonymous and authenticated users,
regardless of their signup/reportback activity for the campaign. 
