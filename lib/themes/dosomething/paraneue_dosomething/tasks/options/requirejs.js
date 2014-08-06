module.exports = {
  options: {
    dir: "dist/js/",
    baseUrl: "js/",
    mainConfigFile: "js/config.js",
    skipDirOptimize: true,
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
  dev: {
    // Include console & debugger statements, and override DEBUG global to be true on "dev" builds
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
  debug: {
    // Create a "beautified" copy of the production build.
    // This can be toggled in Theme Settings for easier debugging on browsers
    // without source maps. *cough* Internet Explorer 8 *cough*
    options: {
      dir: "dist/debug/",
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
