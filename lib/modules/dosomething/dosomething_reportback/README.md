# DoSomething Reportback

This module provides a custom entity for a User Reportback.

A reportback can have multiple images associated with it.  This currently implemented via a Drupal Image field
attached to the reportback, to use Field's built in multi-upload.

## Creating Reportbacks

External apps should call the dosomething_reportback_insert_reportback or dosomething_reportback_update_reportback
functions.

There is only one reportback per user per campaign per campaign run.  What this means is that during a 
campaign run, if a user wants reportback again on a campaign they've reported back for, they are presented 
with the update form for the active reportback instead of a new create reportback form.

## Reportback Log

Our data team still wants the ability to see reportback activity over time though, instead of just that one 
last updated record, hence the dosomething_reportback_log table.

Ideally, we'd stash all the reportback transaction activity on the User document in mongo instead of in this 
log table to avoid it being huge. When we get there, we could move this table to the User document.
