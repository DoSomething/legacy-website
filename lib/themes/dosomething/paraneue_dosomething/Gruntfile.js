/* jshint node:true */
"use strict";

module.exports = function(grunt) {
  // measures the time each task takes
  require('time-grunt')(grunt);

  // Load tasks from `/tasks`
  grunt.loadTasks('tasks');

  // Load plugin configuration from `tasks/options`.
  require('load-grunt-config')(grunt, {
    configPath: require('path').join(process.cwd(), 'tasks/options'),
    init: true,
    config: {
      pkg: grunt.file.readJSON("package.json")
    }
  });
};

