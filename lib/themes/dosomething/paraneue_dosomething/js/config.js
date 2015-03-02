/**
 * We configure RequireJS options, paths, and shims here.
 *
 *  - paths: Load any Bower components in here.
 *  - shim: Shim any non-AMD scripts.
 *  - modules: Configure outputted build files.
 *
 *  @see https://github.com/jrburke/r.js/blob/master/build/example.build.js
 */

require.config({
  paths: {
    "almond": "../bower_components/almond/almond",
    "fixed-sticky": "../bower_components/filament-sticky/fixedsticky",
    "jquery": "../bower_components/jquery/jquery",
    "jquery-once": "../bower_components/jquery-once/jquery.once",
    "jquery-unveil": "../bower_components/unveil/jquery.unveil",
    "jquery-iecors": "../bower_components/jquery.iecors/jquery.iecors",
    "lodash": "../bower_components/lodash/dist/lodash",
    "mailcheck": "../bower_components/mailcheck/src/mailcheck",
    "raf" : "../bower_components/raf.js/raf",
    "text": "../bower_components/requirejs-text/text",
  },
  packages: [
    {
      name: "neue",
      location: "../../bower_components/neue/js"
    },
    {
      name: "modal",
      location: "../../bower_components/dosomething-modal/js",
      main: "modal"
    },
    {
      name: "validation",
      location: "../../bower_components/dosomething-validation/js",
      main: "validation"
    }
  ],
  stubModules: ["text"],
  shim: {
    "jquery-once": { deps: ["jquery"] },
    "jquery-unveil": { deps: ["jquery"] },
    "fixed-sticky": { deps: ["jquery"] },
    "mailcheck": { exports: "Kicksend.mailcheck" }
  },
  modules: [
    {
      name: "lib",
      create: true,
      include: [
        "almond",
        "fixed-sticky",
        "jquery",
        "jquery-once",
        "jquery-unveil",
        "jquery-iecors",
        "mailcheck",
        "lodash",
        "raf",
      ]
    },
    {
      name: "app",
      insertRequire: ["app"],
      exclude: [
        "almond",
        "fixed-sticky",
        "jquery",
        "jquery-once",
        "jquery-unveil",
        "jquery-iecors",
        "mailcheck",
        "lodash"
      ]
    }
  ]
});
