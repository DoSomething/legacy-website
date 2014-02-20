# DoSomething Campaign

This module defines the campaign content type and its various pages.

* The `dosomething_user` and `dosomething_signup` modules handle the actual
campaign signups.
* The `dosomething_reportback` module handles creating and
updating user reportbacks for the campaign.


## Pitch Page

The pitch page is a custom view mode for the Campaign node type.

It is displayed for anonymous users, or auth users who have not
signed up for the campaign.

For anonymous users, the signup button opens up a login/register modal.  Upon
signing in, the user will be signed up for the campaign, and directed to the
action page.

For users already authenticated, the signup button will up the user and direct
the user to the action page.

A staff user is able to view the pitch page by navigating to `node/[nid]/pitch`.


## Action Page

The action page is actually just the "full" view mode of the Campaign node type.
It is displayed for authenticated users who have signed up for the
campaign.

A staff user will view the action page by default when they view the campaign,
see `dosomething_campaign_entity_view_mode_alter().`

The Action page includes a user reportback form, where the user can reportback
on the campaign. Upon submitting, the user is directed to the confirmation page.

If a user who has reported back navigates to the campaign again, they are able
to update their reportback submission.


## Confirmation Page

The confirmation page is implemented via a menu hook and page callback, with path
`node/[nid]/confirmation`.

It is displayed after a user submits the reportback form.  The user is only able
to access the confirmation page if they have reported back for the campaign.  A
staff user is able to view the confirmation page at any time.

The confirmation page displays 3 recommended campaigns for the user.  This is
determined by first finding published campaigns which are staff picks, that the
user has not signed up for.

If there are less than 3 staff picks that the user hasn't signed up for, the
confirmation page will also display published campaigns which share the same
Primary Cause, for which the user has not signed up for.



