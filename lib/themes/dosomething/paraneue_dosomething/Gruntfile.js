/* jshint node:true */
"use strict";

module.exports = function(grunt) {
  // @TODO: Remove this in a bit.
  var sass = require('node-sass');
  var fs = require('fs');

  // measures the time each task takes
  require('time-grunt')(grunt);

  // Load tasks from `/tasks`
  grunt.loadTasks('tasks');

  function writeFile(path, contents) {
    if(grunt.file.exists(path)) {
      grunt.file.delete(path);
    }

    grunt.file.write(path, contents);
  }

  grunt.registerTask('nodesass', function() {
    console.log(sass.info());

    var result = sass.renderSync({
      file: __dirname + '/scss/app.scss',
      outFile: __dirname + '/dist/app.min.css',
      outputStyle: 'compressed',
      sourceMap: true
    });

    writeFile(__dirname + '/dist/app.min.css', result.css);
  });

  // Load plugin configuration from `tasks/options`.
  require('load-grunt-config')(grunt, {
    configPath: require('path').join(process.cwd(), 'tasks/options'),
    init: true,
    config: {
      pkg: grunt.file.readJSON("package.json")
    }
  });
};

