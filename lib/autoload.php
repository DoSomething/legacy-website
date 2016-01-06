<?php

/**
 * Require Composer's class loader so we don't have to worry
 * about manually loading any PSR-4 or vendor classes.
 *
 * This file is referenced from `settings.php` during Drupal's
 * standard bootstrapping process, and directly from PHPUnit
 * unit tests (which do *not* bootstrap the full Drupal env.)
 *
 * For further reading:
 * https://getcomposer.org/doc/01-basic-usage.md#autoloading
 */
require __DIR__ . '/../vendor/autoload.php';
