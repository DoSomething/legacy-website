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
    "fixed-sticky": "../node_modules/fixed-sticky/fixedsticky",
    "jquery": "../node_modules/jquery/dist/jquery",
    "jquery-once": "../node_modules/jquery-once/jquery.once",
    "jquery-unveil": "../node_modules/unveil/jquery.unveil",
    "jquery-iecors": "../node_modules/jquery.iecors/jquery.iecors",
    "lodash": "../node_modules/lodash/index",
    "mailcheck": "../node_modules/mailcheck/src/mailcheck",
    "neue": "../node_modules/dosomething-neue/dist/neue",
    "modal": "../node_modules/dosomething-modal/dist/modal",
    "validation": "../node_modules/dosomething-validation/dist/validation",
    "raf" : "../node_modules/raf.js/raf",
    "text": "../bower_components/requirejs-text/text",
  },
  stubModules: ["text"],
  shim: {
    "jquery-once": { deps: ["jquery"] },
    "jquery-unveil": { deps: ["jquery"] },
    "fixed-sticky": { deps: ["jquery"] }
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
        "raf"
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
        "lodash",
        "raf"
      ]
    }
  ]
});
