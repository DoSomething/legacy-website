module.exports = {
  prod: {
    options: {
      report: "gzip"
    },
    files: {
      "dist/app.js": ["dist/app.js"],
    }
  },
  dev: {
    options: {
      mangle: false,
      compress: false,
      beautify: true
    },
    files: {
      "dist/app.js": ["dist/app.js"],
    }
  }
}
