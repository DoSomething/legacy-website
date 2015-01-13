module.exports = {
  process: {
    src: "dist/app.min.css",
    options: {
      map: true,
      processors: [
        require('autoprefixer-core')({
          browsers: ['last 4 versions', 'Firefox ESR', 'Opera 12.1']
        }).postcss,
        require('css-mqpacker').postcss
      ]
    }
  }
};
