module.exports = {
  dev: {
    files: {
      "dist/app.css": "scss/app.scss",
      "dist/ie.css": "scss/ie.scss"
    },
    options: {
      outputStyle: "nested",
      sourceComments: "normal"
    }
  },
  prod: {
    files: {
      "dist/app.min.css": "scss/app.scss",
      "dist/ie.min.css": "scss/ie.scss"
    },
    options: {
      outputStyle: "compressed",
      sourceComments: "map"
    }
  }
}
