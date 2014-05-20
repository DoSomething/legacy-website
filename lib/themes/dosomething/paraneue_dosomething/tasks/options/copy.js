module.exports = {
  assets: {
    files: [
      {expand: true, src: ["images/**"], dest: "dist/"},
      {expand: true, src: ["bower_components/**"], dest: "dist/"},
    ]
  },
  js: {
    files: [
      {expand: true, src: ["js/**"], dest: "dist/"},
    ]
  }
}
