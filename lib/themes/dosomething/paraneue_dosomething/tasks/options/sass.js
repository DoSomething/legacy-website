module.exports = {
  dev: {
    files: {
      "dist/app.css": "dist/scss/app.scss",
      "dist/ie.css": "dist/scss/ie.scss"
    },
    options: {
      outputStyle: "nested",
      sourceComments: "normal"
    }
  },
  prod: {
    files: {
      "dist/app.min.css": "dist/scss/app.scss",
      "dist/ie.min.css": "dist/scss/ie.scss"
    },
    options: {
      outputStyle: "compressed",
      sourceComments: "map"
    }
  }
}
