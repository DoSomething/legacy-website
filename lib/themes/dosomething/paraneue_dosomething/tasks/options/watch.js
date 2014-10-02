module.exports = {
  sass: {
    files: ["scss/**/*.{scss,sass}"],
    tasks: ["lint:css", "sass:prod", "test:css"]
  },
  js: {
    files: ["js/**/*.js", "tests/**/*.js"],
    tasks: ["lint:js", "requirejs:dev"]
  },
  assets: {
    files: ["assets/**/*", "bower_components/**/*"],
    tasks: ["copy:assets"]
  }
}
