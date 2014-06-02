module.exports = {
  sass: {
    files: ["scss/**/*.{scss,sass}"],
    tasks: ["lint:css", "sass:compile", "test:css"]
  },
  js: {
    files: ["js/**/*.js", "tests/**/*.js"],
    tasks: ["lint:js", "requirejs:dev", "test:js"]
  },
  assets: {
    files: ["assets/**/*", "bower_components/**/*"],
    tasks: ["copy:assets"]
  }
}
