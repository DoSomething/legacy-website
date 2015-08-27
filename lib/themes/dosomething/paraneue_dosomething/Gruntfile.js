/* eslint-disable */
"use strict";

var webpack = require('webpack');
var ExtractTextPlugin = require("extract-text-webpack-plugin");

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
     * Build assets with Webpack. Bundle scripts and transpile JavaScript using
     * Babel, and pre-process CSS with LibSass.
     *
     * We also post-process CSS with PostCSS. We use Autoprefixer to automatically
     * add vendor-prefixes for appropriate browsers. We use CSS-MQPacker to
     * concatenate all media queries at the end of our built stylesheets.
     */
    webpack: {
      options: {
        entry: {
          app: './js/app.js',
          lib: './js/lib.js'
        },
        output: {
          path: 'dist',
          filename: '[name].js'
        },
        resolve: {
          root: require('path').resolve(__dirname, './js')
        },
        module: {
          loaders: [
            { test: /\.js$/, exclude: /node_modules/, loader: 'babel-loader'},
            { test: /\.html$/, exclude: /node_modules/, loader: 'raw-loader'},
            { test: /\.(png|jpg|gif|eot|woff|svg|ttf)$/, loader: 'url-loader?limit=4096' },
            {
              test: /\.scss$/,
              loader: ExtractTextPlugin.extract('css-loader?sourceMap!postcss-loader!sass-loader?sourceMap')
            },
          ]
        },
        postcss: function() {
          return [
            require('autoprefixer-core')({
              browsers: ['last 4 versions', 'Firefox ESR', 'Opera 12.1']
            }),
            require('css-mqpacker').postcss
          ];
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
            filename: "lib.js"
          }),
          new webpack.optimize.UglifyJsPlugin({
            compress: {
              warnings: false,
              drop_console: true,
              drop_debugger: true,
              dead_code: true
            }
          }),
          new ExtractTextPlugin('app.min.css')
        ]
      },

      // On development builds, include source maps & set debug flags
      debug: {
        devtool: 'eval-cheap-module-source-map',
        plugins: [
          new webpack.DefinePlugin({
            DEBUG: true,
            PRODUCTION: false
          }),
          new webpack.optimize.CommonsChunkPlugin({
            name: "lib",
            filename: "lib.js"
          }),
          new ExtractTextPlugin('app.min.css')
        ],

        // Keep Webpack task running & watch for changes.
        keepalive: true,
        watch: true,
        cache: true
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
            "node_modules/@dosomething/forge/js/**/*.js",
            "!node_modules/@dosomething/forge/js/modernizr/**/*.js",
            "node_modules/@dosomething/forge/scss/**/*.scss",
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
          "node_modules/@dosomething/forge/js/modernizr/checked.js",
          "node_modules/@dosomething/forge/js/modernizr/label-click.js"
        ]
      }
    },

    /**
     * Lint JavaScript using ESLint.
     */
    eslint: {
      all: ["js/**/*.js"]
    },

    /**
     * Lint SCSS using Sasslint.
     */
    sasslint: {
      all: ["scss/**/*.scss"]
    },
  });

  /**
   * Register Grunt aliases.
   */

  // > grunt
  // Build for development & watch for changes.
  grunt.registerTask('default', ['build:debug']);

  // > grunt build
  // Build for production.
  grunt.registerTask('build', ['clean:dist', 'modernizr:all', 'webpack:prod']);

  // > grunt build:debug
  // Build for development.
  grunt.registerTask('build:debug', ['clean:dist', 'modernizr:all', 'webpack:debug']);

  // > grunt test
  // Run included unit tests and linters.
  grunt.registerTask('test', ['eslint', 'sasslint']);

};

