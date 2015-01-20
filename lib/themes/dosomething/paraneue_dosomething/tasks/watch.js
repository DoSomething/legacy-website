module.exports = {
  sass: {
    files: ["scss/**/*.{scss,sass}"],
    tasks: ["scsslint", "sass",  "postcss"]
  },
  js: {
    files: ["js/**/*.js", "tests/**/*.js"],
    tasks: ["jshint", "requirejs"]
  },
  assets: {
    files: ["assets/**/*", "bower_components/**/*"],
    tasks: ["copy:assets"]
  }
};
