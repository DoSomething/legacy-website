/* jshint node:true */
"use strict";

var webpack = require('webpack');

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
     * Build JavaScript with Webpack.
     */
    webpack: {
      options: {
        entry: {
          app: './js/app.js',
          lib: './js/lib.js'
        },
        output: {
          filename: 'dist/app.js'
        },
        resolve: {
          root: require('path').resolve(__dirname, './js')
        },
        module: {
          loaders: [
            { test: /\.js$/, exclude: /node_modules/, loader: 'babel-loader'},
            { test: /\.html$/, exclude: /node_modules/, loader: 'raw-loader'}
          ]
        }
      },

      // On production builds, disable source maps & set production flags
      prod: {
        plugins: [
          new webpack.DefinePlugin({
            DEBUG: false,
            PRODUCTION: true
          }),
          new webpack.optimize.CommonsChunkPlugin({
            name: "lib",
            filename: "dist/lib.js"
          }),
          new webpack.optimize.UglifyJsPlugin({
            compress: {
              warnings: false,
              drop_console: true,
              drop_debugger: true,
              dead_code: true
            }
          })
        ]
      },

      // On development builds, include source maps & set debug flags
      debug: {
        devtool: '#inline-source-map',
        plugins: [
          new webpack.DefinePlugin({
            DEBUG: true,
            PRODUCTION: false
          }),
          new webpack.optimize.CommonsChunkPlugin({
            name: "lib",
            filename: "dist/lib.js"
          })
        ]
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
            "node_modules/dosomething-neue/js/**/*.js",
            "!node_modules/dosomething-neue/js/modernizr/**/*.js",
            "node_modules/dosomething-neue/scss/**/*.scss",
            "node_modules/dosomething-modal/src/**/*.js",
            "node_modules/dosomething-validation/src/**/*.js"
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
          "node_modules/dosomething-neue/js/modernizr/checked.js",
          "node_modules/dosomething-neue/js/modernizr/label-click.js"
        ]
      }
    },

    /**
     * Lint JavaScript using ESLint.
     */
    eslint: {
      target: ["js/**/*.js"]
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
        tasks: ["webpack:debug", "jshint"]
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
  grunt.registerTask('build', ['clean:dist', 'copy:assets', 'sass:prod', 'postcss:prod', 'webpack:prod', 'modernizr:all']);

  // > grunt build:debug
  // Build for development.
  grunt.registerTask('build:debug', ['clean:dist', 'copy:assets', 'sass:debug', 'postcss:debug', 'webpack:debug', 'modernizr:all']);

  // > grunt test
  // Run included unit tests and linters.
  grunt.registerTask('test', ['eslint']);

};

