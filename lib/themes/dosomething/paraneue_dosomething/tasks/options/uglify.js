module.exports = {
  prod: {
    options: {
      report: "gzip",
      compress: {
        dead_code: true,
        drop_debugger: true,
        join_vars: true,
        drop_console: true,
        global_defs: {
          DEBUG: false
        }
      },
      mangle: {
        except: ['jQuery', '$', 'Modernizr', 'NEUE']
      }
    },
    files: {
      "dist/app.js": [
        "bower_components/jquery/jquery.js",
        "bower_components/jquery-once/jquery.once.js",
        "bower_components/unveil/jquery.unveil.js",
        "dist/app.js"
      ]
    }
  },
  dev: {
    options: {
      mangle: false,
      compress: false,
      beautify: true
    },
    files: {
      "dist/app.js": [
        "bower_components/jquery/jquery.js",
        "bower_components/jquery-once/jquery.once.js",
        "bower_components/unveil/jquery.unveil.js",
        "bower_components/requirejs/require.js",
        "js/main.js",
        "js/config.dev.js"
      ]
    }
  }
}
