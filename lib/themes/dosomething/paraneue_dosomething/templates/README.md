Templates
=========

Place tpl files inside this directory if you need to override them.


Campaign
--------

* `node--campaign.tpl.php` - Full node view of a campaign, a.k.a the Action Page

* `node--campaign--closed.tpl.php` - Displayed for a closed campaign

* `node--campaign--pitch.tpl.php` - Pitch page display of a campaign

* `node--campaign--sms-game.tpl.php` - Displayed for campaigns of type SMS Game

* `reportback-confirmation.tpl.php` - Displayed after a user submits the campaign's reportback form.

* `submit-campaign-idea.tpl.php` - Block content callback for the "DS Submit Campaign Idea" block, defined in DoSomething Campaign.  Displays a form which has been configured in Google Docs, to submit the data to the doc. The form redirect is defined from within the Google Doc.

Campaign Run
------------
* `node--campaign_run.tpl.php` - Node view of campaign run upon editing and saving.

Reportback
----------
* `reportback.tpl.php` - Staff only view of a reportback entity. e.g. /reportback/[id]
* `reportback-form-images.tpl.php` - Displays a reportback's images, and last updated. @see `dosomething_reportback_form()`
