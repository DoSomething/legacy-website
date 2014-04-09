# DoSomething Reportback

This module provides a custom entity for a User Reportback.

## Reportback Files

A reportback has at least 1 image associated with it.  This currently implemented via 
a custom db table, `dosomething_reportback_file`.

## Creating and updating Reportbacks

There is only one reportback per user per campaign per campaign run.  What this means is that during a 
campaign run, if a user wants reportback again on a campaign they've reported back for, they are presented 
with the update form for the active reportback instead of a new create reportback form.

## Reportback Log

Our data team still wants the ability to see reportback activity over time though, instead of just that one 
last updated record, hence the `dosomething_reportback_log` table.

Ideally, we'd stash all the reportback transaction activity on the User document in mongo instead of in this 
log table to avoid it being huge. When we get there, we could move this table to the User document.

## Reportback Field

An administrator can implement a custom reportback field on an existing campaign node 
by configurating the "Reportback Fields" section in the campaign node edit form.

This writes a record into the `dosomething_reportback_field` table, storing the
Reportback field name, label, and type.

There is also a `dosomething_reportback_field_data` table, which stores the
user values for each reportback field.
