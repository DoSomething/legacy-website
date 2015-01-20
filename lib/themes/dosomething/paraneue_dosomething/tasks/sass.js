var fs = require('fs');
var path = require('path');
var sass = require('node-sass');

module.exports = function(grunt) {
  function writeFile(path, contents) {
    if(grunt.file.exists(path)) {
      grunt.file.delete(path);
    }

    grunt.file.write(path, contents);
  }

  grunt.registerTask('sass', function() {
    console.log(sass.info());

    var inFile = path.resolve('scss/app.scss');
    var outFile = path.resolve('dist/app.min.css');

    var result = sass.renderSync({
      file: inFile,
      outFile: outFile,
      outputStyle: 'compressed',
      sourceMap: false
    });

    writeFile(outFile, result.css);
  });
};
