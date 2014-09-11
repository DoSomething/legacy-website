module.exports = {
  dev: {
    files: {
      "dist/app.css": "scss/app.scss"
    },
    options: {
      outputStyle: "nested",
      sourceComments: "normal"
    }
  },
  prod: {
    files: {
      "dist/app.min.css": "scss/app.scss"
    },
    options: {
      outputStyle: "compressed",
      sourceComments: "map"
    }
  }
}
