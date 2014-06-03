module.exports = function(grunt) {
  // The `build` task lints, tests, and compiles assets.
  grunt.registerTask("build", ["clean:dist", "copy:assets", "copy:source", "sass:prod", "requirejs:debug"]);

  // The `prod` build task is used when building for production. Since compiled assets
  // are ignored in version control, this is run in Continuous Integration on deploy.
  grunt.registerTask("prod", ["clean:dist", "copy:assets", "copy:source", "sass:dev", "sass:prod", "requirejs:dev", "requirejs:prod"]);
}
