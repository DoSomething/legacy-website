module.exports = {
  options: {
    force: true,
    jshintrc: true,
    reporter: require("jshint-stylish")
  },
  all: [
    "js/**/*.js",
    "!js/respond.custom.js",
    "!js/vendor/**/*.js",
    "tests/**/*.js",
    "!tests/lib/**/*.js"
  ]
}
