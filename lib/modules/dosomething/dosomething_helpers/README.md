# DoSomething Helpers

General cross-module helper functions go here.

## Content Type Theme Registry

The 'dosomething_helpers_theme_registry_alter' in the theme.inc alters the theme
registry to check for the existence of a content type's node--[NAME].tpl.php
file within the module's directory.  This allows for a base template file in
the module directory, to serve as a guide for theming.

The registry alter will not work for a content type unless it is added into the
`dosomething_helpers_modules` variable, which is defined in the
`dosomething_helpers_strongarm` file.

## Get EntityReference Parents

The `dosomething_helpers.module` file contains functions used to query specified
entityreference fields for a given node nid, and return the parent nodes that
reference it.

These functions are used on the full view mode of nodes like Facts and Images, to
display all nodes that reference them.

## Node Form Enhancements

This module is responsible for adding all of those character counters in the
node edit forms.
