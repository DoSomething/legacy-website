module.exports = {
  sass: {
    files: ["scss/**/*.{scss,sass}"],
    tasks: ["lint:css", "sass:compile", "test:css"]
  },
  js: {
    files: ["js/**/*.js", "tests/**/*.js"],
    tasks: ["lint:js", "requirejs:compile", "test:js"]
  },
  assets: {
    files: ["assets/**/*"],
    tasks: ["copy"]
  }
}
