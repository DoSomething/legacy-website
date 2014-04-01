module.exports = function(grunt) {
  // The `build` task lints, tests, and compiles assets.
  grunt.registerTask("build", ["lint", "test", "clean:dist", "sass:compile", "copy:main", "uglify:dev"]);

  // The `prod` build task is used when building for production. Since compiled assets
  // are ignored in version control, this is run in Continuous Integration on deploy.
  grunt.registerTask("prod", ["clean:dist", "sass:compile", "cssmin:minify", "copy:main", "requirejs:compile"]);
}
