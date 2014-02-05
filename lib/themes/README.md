DoSomething specific custom themes live here.

We need this directory in order to make symlinking during development easier.

## Theming Stack Overview

 - `Neue` has CSS and JS for basic layout. Exports a SCSS helper file with mixins and variables for app dev. It is imported into `Paraneue` and `Paraneue_DoSomething` using a `bower.json` file in each respective directory.
 - `Paraneue` pulls in Neue's CSS and JS, and jQuery. It themes Drupal base features and nothing more. Paraneue does **not** include its own app-level CSS or JS.
 - `Paraneue_DoSomething` has app-level templates, SCSS, and JS (i.e. styles and scripts for pitch/action page) and a build system to keep that up to date.
