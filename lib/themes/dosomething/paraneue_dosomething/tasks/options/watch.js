module.exports = {
  sass: {
    files: ["scss/**/*.{scss,sass}"],
    tasks: ["lint:css", "sass:compile", "test:css"]
  },
  js: {
    files: ["js/**/*.js", "tests/**/*.js"],
    tasks: ["lint:js", "test:js"]
  },
  requirejs: {
    files: ["js/config.js", "js/config.dev.js"],
    tasks: ["uglify:dev"]
  },
  assets: {
    files: ["assets/**/*"],
    tasks: ["copy"]
  }
}
