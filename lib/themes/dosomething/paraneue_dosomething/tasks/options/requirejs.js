module.exports = {
  options: {
    baseUrl: "js/",
    name: "../bower_components/requirejs/require",
    mainConfigFile: "js/main.js",
    optimize: "uglify2",
    preserveLicenseComments: false,
    generateSourceMaps: true,
    out: "dist/app.js"
  },
  dev: {
    options: {
      uglify2: {
        compress: {
          global_defs: {
            DEBUG: true
          }
        }
      }
    }
  },
  prod: {
    options: {
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
    }
  }
}
