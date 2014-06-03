module.exports = {
  sass: {
    files: ["scss/**/*.{scss,sass}"],
    tasks: ["lint:css", "copy:source", "sass:prod", "test:css"]
  },
  js: {
    files: ["js/**/*.js", "tests/**/*.js"],
    tasks: ["lint:js", "copy:source", "requirejs:dev", "test:js"]
  },
  assets: {
    files: ["assets/**/*", "bower_components/**/*"],
    tasks: ["copy:assets"]
  }
}
