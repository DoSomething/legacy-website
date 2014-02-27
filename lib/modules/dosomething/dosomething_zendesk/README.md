# DoSomething Zendesk

A module to interact with the Zendesk PHP API Client Library:

https://github.com/zendesk/zendesk_api_client_php

## Installation

Composer must be installed in order install the PHP library.

The repository https://github.com/zendesk/zendesk_api_client_php should be
cloned into the Drupal libraries directory with directory name "zendesk".

Within the libraries/zendesk directory, run `composer install` to install the
Zendesk PHP API library.  This will generate a vendor/autoload.php file, which
`dosomething_zendesk_libraries_info` references to load the Zendesk PHP API
Client Library.

## Usage

The `dosomething_zendesk_form` will create a new Zendesk ticket, setting the
ticket requester as the currently logged in user.
