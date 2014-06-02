module.exports = {
  options: {
    baseUrl: "js/",
    name: "../bower_components/almond/almond",
    mainConfigFile: "js/main.js",
    insertRequire: ["main"],
    optimize: "uglify2",
    preserveLicenseComments: false,
    generateSourceMaps: true,
    out: "dist/app.js"
  },
  dev: {
    options: {
      uglify2: {
        output: {
          beautify: true
        },
        compress: {
          global_defs: {
            DEBUG: true
          }
        },
        mangle: false
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
