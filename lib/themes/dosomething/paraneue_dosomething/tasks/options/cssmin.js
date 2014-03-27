module.exports = {
  minify: {
    options: {
      report: "gzip"
    },
    files: {
      "dist/app.css": ["dist/app.css"],
      "dist/ie.css": ["dist/ie.css"]
    }
  }
}
