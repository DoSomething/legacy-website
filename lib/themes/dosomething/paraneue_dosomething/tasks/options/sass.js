module.exports = {
  dev: {
    files: {
      "dist/app.css": "scss/app.scss"
    },
    options: {
      style: "nested",
      lineNumbers: true,
      bundleExec: true
    }
  },
  prod: {
    files: {
      "dist/app.min.css": "scss/app.scss"
    },
    options: {
      style: "compressed",
      bundleExec: true
    }
  }
}
