module.exports = {
  options: {
    out: "dist/app.min.js",
    baseUrl: "js/",
    name: "../bower_components/almond/almond",
    mainConfigFile: "js/main.js",
    include: "main",
    insertRequire: ["main"],
    preserveLicenseComments: false,
    generateSourceMaps: true,
    optimize: "uglify2",
    uglify2: {
      compress: {
        dead_code: true,
        drop_debugger: true,
        drop_console: true,
        global_defs: {
          DEBUG: false
        }
      }
    }
  },
  debug: {
    // Override DEBUG global to be true on "dev" builds
    options: {
      uglify2: {
        compress: {
          drop_debugger: false,
          drop_console: false,
          global_defs: {
            DEBUG: true
          }
        },
      }
    }
  },
  dev: {
    // Create a "beautified" copy of the production build
    options: {
      out: "dist/app.js",
      generateSourceMaps: false,
      uglify2: {
        output: {
          comments: true,
          beautify: true
        },
        mangle: false
      }
    }
  },
  prod: {
    // Uses all default settings
    // (minifies code, drops console/debuggers, & mangles variable names)
  }
}
