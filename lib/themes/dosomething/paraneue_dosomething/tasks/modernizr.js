module.exports = {
  all: {
    "devFile": "remote",
    "outputFile": "dist/modernizr.js",
    "files" : {
      "src": [
        "js/**/*.js",
        "scss/**/*.scss",
        "bower_components/neue/js/**/*.js",
        "bower_components/neue/scss/**/*.scss"
      ]
    },
    "extra" : {
      "shiv" : false,
      "printshiv" : false,
      "load" : true,
      "mq" : false,
      "video": false
    },
  }
}
