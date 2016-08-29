var webpack = require('webpack');
var buildConfig = require('@dosomething/webpack-config');

var config = buildConfig({
  entry: {
    app: ['babel-polyfill', './js/app.js'],
    lib: './js/lib.js',
    onboarding: './js/onboarding.js',
  },

  // HACK: For old AMD code, we assume a project root. To keep
  // this functioning, we'll tell Webpack to resolve "absolute"
  // paths as if they were coming from the 'js/' directory.
  resolve: {
    root: require('path').resolve(__dirname, './js')
  },
});

// Add CommonsChunkPlugin to ensure we only include vendor
// scripts once, in our `lib.js` bundle.
config.plugins.push(
  new webpack.optimize.CommonsChunkPlugin({
    name: "lib",
    filename: "lib.js"
  })
);

// Add 'raw-loader' to allow us to import HTML files as strings
// for use with Lodash's built-in templating function.
config.module.loaders.push({ test: /\.html$/, exclude: /node_modules/, loader: 'raw-loader'});

module.exports = config;
