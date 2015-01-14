module.exports = function(grunt) {
  // The `build` task lints, tests, and compiles assets.
  grunt.registerTask("build", ["copy:assets", "nodesass", "postcss:process", "requirejs:dev", "modernizr:dist"]);

  // The `prod` build task is used when building for production. Since compiled assets
  // are ignored in version control, this is run in Continuous Integration on deploy.
  grunt.registerTask("prod", ["copy:assets", "nodesass", "postcss:process", "requirejs:debug", "requirejs:prod", "modernizr:dist"]);
}
