module.exports = {
  all: {
    "devFile": "remote",
    "outputFile": "dist/modernizr.js",
    "files" : {
      "src": [
        "js/**/*.js",
        "scss/**/*.scss",
        "bower_components/neue/js/**/*.js",
        "!bower_components/neue/js/modernizr/**/*.js",
        "bower_components/neue/scss/**/*.scss"
      ]
    },
    extensibility : {
      "cssclassprefix": "modernizr-"
    },
    "extra" : {
      "addtest": true,
      "shiv" : false,
      "teststyles": true,
      "printshiv" : false,
      "load" : true,
      "mq" : false,
      "video": false
    },
    "matchCommunityTests": true,
    "customTests": [
      "bower_components/neue/js/modernizr/checked.js",
      "bower_components/neue/js/modernizr/label-click.js"
    ]
  }
};
