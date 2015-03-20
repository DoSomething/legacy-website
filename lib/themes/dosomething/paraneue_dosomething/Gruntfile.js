/* jshint node:true */
"use strict";

module.exports = function(grunt) {
  // Load tasks & measure timing
  require('time-grunt')(grunt);
  require('load-grunt-tasks')(grunt);

  // Configure Grunt tasks
  grunt.initConfig({
    /**
     * Clean the `dist/` folder between builds.
     */
    clean: {
      'dist': ['dist/']
    },

    /**
     * Copy assets into `dist/` directory.
     */
    copy: {
      assets: {
        files: [
          {expand: true, src: ["images/**"], dest: "dist/"}
        ]
      }
    },

    /**
     * Build JavaScript with RequireJS.
     */
    requirejs: {
      options: {
        dir: "dist/js/",
        baseUrl: "js/",
        mainConfigFile: "js/config.js",
        skipDirOptimize: true
      },

      // On production builds, we should minify and drop
      // dead code, `debugger`, and `console.log` statements.
      prod: {
        options: {
          preserveLicenseComments: false,
          generateSourceMaps: false,
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
        }
      },

      // On development builds, include source maps & do not minify.
      debug: {
        options: {
          generateSourceMaps: true,
          optimize: "none"
        }
      }
    },

    /**
     * Pre-process CSS with LibSass.
     */
    sass: {
      // On production builds, minify and remove comments.
      prod: {
        files: {
          'dist/app.min.css': 'scss/app.scss'
        },
        options: {
          outputStyle: 'compressed'
        }
      },

      // On development builds, include source maps & do not minify.
      debug: {
        files: {
          'dist/app.min.css': 'scss/app.scss'
        },
        options: {
          sourceMap: true
        }
      }
    },

    /**
     * Post-process CSS with PostCSS.
     *
     * We use Autoprefixer to automatically add vendor-prefixes for appropriate
     * browsers. We use CSS-MQPacker to concatenate all media queries at the
     * end of our built stylesheets.
     */
    postcss: {
      options: {
        processors: [
          require('autoprefixer-core')({
            browsers: ['last 4 versions', 'Firefox ESR', 'Opera 12.1']
          }).postcss,
          require('css-mqpacker').postcss
        ]
      },

      // On production builds, omit source maps.
      prod: {
        src: ['dist/app.min.css'],
        options: {
          map: false
        }
      },

      // On development builds, include source maps.
      debug: {
        src: ['dist/app.min.css']
      }
    },

    /**
     * Create custom Modernizr build based on referenced CSS
     * classes and JavaScript Modernizr checks.
     */
    modernizr: {
      all: {
        "devFile": "remote",
        "outputFile": "dist/modernizr.js",
        "files" : {
          "src": [
            "js/**/*.js",
            "scss/**/*.scss",
            "bower_components/neue/js/**/*.js",
            "!bower_components/neue/js/modernizr/**/*.js",
            "bower_components/neue/scss/**/*.scss"
          ]
        },
        extensibility : {
          // We prefix all Modernizr classes with `modernizr-` to avoid class conflicts.
          "cssclassprefix": "modernizr-"
        },
        "extra" : {
          "addtest": true,
          "shiv" : false,
          "teststyles": true,
          "printshiv" : false,
          "load" : true,
          "mq" : false,
          "video": false
        },
        "matchCommunityTests": true,
        "customTests": [
          "bower_components/neue/js/modernizr/checked.js",
          "bower_components/neue/js/modernizr/label-click.js"
        ]
      }
    },

    /**
     * Lint JavaScript using JSHint.
     */
    jshint: {
      options: {
        force: true,
        jshintrc: true,
        reporter: require("jshint-stylish")
      },
      all: [
        "js/**/*.js",
        "tests/**/*.js",
        "!tests/lib/**/*.js"
      ]
    },

    /**
     * Watch files for changes, and trigger relevant tasks.
     */
    watch: {
      sass: {
        files: ["scss/**/*.scss"],
        tasks: ["sass:debug", "postcss:debug"]
      },
      js: {
        files: ["js/**/*.js"],
        tasks: ["requirejs:debug", "jshint"]
      },
      assets: {
        files: ["images/**/*"],
        tasks: ["copy:assets"]
      }
    }
  });

  /**
   * Register Grunt aliases.
   */

  // > grunt
  // Build for development & watch for changes.
  grunt.registerTask('default', ['build:debug', 'test', 'watch']);

  // > grunt build
  // Build for production.
  grunt.registerTask('build', ['clean:dist', 'copy:assets', 'sass:prod', 'postcss:prod', 'requirejs:prod', 'modernizr:all']);

  // > grunt build:debug
  // Build for development.
  grunt.registerTask('build:debug', ['clean:dist', 'copy:assets', 'sass:debug', 'postcss:debug', 'requirejs:debug', 'modernizr:all']);

  // > grunt test
  // Run included unit tests and linters.
  grunt.registerTask('test', ['jshint']);

};

