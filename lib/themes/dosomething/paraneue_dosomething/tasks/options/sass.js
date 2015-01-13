module.exports = {
  dev: {
    files: {
      "dist/app.css": "scss/app.scss"
    },
    options: {
      outputStyle: "nested",
      lineNumbers: true,
    }
  },
  prod: {
    files: {
      "dist/app.min.css": "scss/app.scss"
    },
    options: {
      outputStyle: "compressed"
    }
  }
}
