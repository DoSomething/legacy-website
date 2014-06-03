module.exports = {
  assets: {
    files: [
      {expand: true, src: ["images/**"], dest: "dist/"},
      {expand: true, src: ["bower_components/**"], dest: "dist/"},
    ]
  },
  source: {
    files: [
      {expand: true, src: ["scss/**"], dest: "dist/"},
      {expand: true, src: ["js/**"], dest: "dist/"},
    ]
  }
}
