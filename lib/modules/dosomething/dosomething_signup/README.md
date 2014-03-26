# DoSomething Signup

This module provides functionality for users to signup for a node type which
implements it (currently only Campaigns).

Technically, a signup is simply a record in the `dosomething_signup` table, 
which stores the user uid, the node nid, and the timestamp of the signup.

## View Signups

Each campaign has a corresponding `node/[nid]/signups` path, which calls
a `node_signups` view, displaying the signups for the given node.

Users with the custom `view any signup` permission are able to access this view. 

## Unsignup

Members (authenticated users) are currently unable to remove their signup from 
a node.

Staff users (see `dosomething_user`) who signed up for a campaign are able to
remove their signup record at `node/[nid]/unsignup`.  This is available for
testing purposes.


## Third Party Opt-In

Currently we opt-in users to Mailchimp and Mobilecommons upon signup, depending
on the node they are signing up for.

Users with `administer third party communication` are able to set custom 
Mailchimp groups and Mobilecommons opt-in paths for specific nodes at 
`admin/config/services/optins`.

* Currently only staff picks are able to be assigned custom Mailchimp and/or
Mobilecommons opt-in paths.  
* If a user signs up for a non-staff-pick campaign,
they are opted into a general campaign Mobilecommons opt-in path.

Any node which needs a Mailchimp subscription must include a Mailchimp Interest
Group Name, an alphanumeric identifier, and a Mailchimp Grouping ID, a numeric
ID which the Group belongs to. 

## Signup Data Form

Some campaigns collect additional data during the signup process.  Examples:

* __Teens For Jeans__
    * Upon signup, user must select/confirm what school they belong to, or 
    indicate that they are not affiliated with a school. 

* __Comeback Clothes__
    * Users can optionally enter/confirm their address to be sent a promotional banner.

* __Thumb Wars__
    * Upon signup, user is prompted why they want thumb socks, and must enter/confirm
    their mailing address to be sent the thumb socks.

* __Give A Spit__
    * Upon signup, user is prompted to enter/confirm birthdate.

A "Signup Data Form" refers to the form that collects this additional signup 
data.  The form configuration is stored in a custom table, `dosomething_signup_data_form`, 
with fields:

* `nid` - The node nid which the `signup_data_form` record corresponds to.

* `status` - If this is 1, the form is considered active and rendered on the campaign template.

* `required` - If this is 1, the user must complete the form to access the campaign
action page.  If they navigate away from the campaign without submitting the form, 
they will be presented with the signup form again until they submit. Currently not implemented.

* `required_allow_skip` - If this is 1, the user is presented with the option to 
skip on a required form.  We track that they submitted, and don't prompt again.
Currently not implemented.

* `link_text` - The text to display on the link that opens a signup data form 
in a modal.

* `form_header` - Header text displayed on the signup data form.

* `form_copy` - Copy text displayed on the signup data form.

* `confirm_msg` - Text displayed in the message that appears after submission.

* `collect_why_signedup` - Whether or not to prompt user for why they signed up. 
Currently not implemented.

* `why_signedup_label` - The label to display on the textarea for user to enter
reason why they signed up.  Currently not implemented.

* `collect_user_address` - Whether or not to prompt user for mailing address.

* `collect_user_school` - Currently not implemented.

* `collect_user_mobile` - Currently not implemented.

* `collect_user_birthdate` - Currently not implemented.

Upon submititng a Signup Data Form, the relevant user information is stored to
the user object (address, school, birthdate) and the timestamp of submission is
stored in the `dosomething_signup.signup_data_form_timestamp` column.

If the form is set to `collect_why_signedup`, the user's input for the `why_signedup`
field is stored in the `dosomething_signup.why_signedup` column.

The `dosomething_signup.signup_data_form.inc` file code contains:

*  `_dosomething_signup_node_signup_data_form`
To be called from within a node edit form.  Adds form elements which correspond 
to the values in the node nid's `dosomething_signup_data_form` record.

* `dosomething_signup_user_signup_data_form`
The form the user is presented with to enter additional signup data, dynamically
rendered based on the values in the node `dosomething_signup_data_form` record.

