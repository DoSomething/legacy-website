module.exports = {
  all: {
    options: {
      dir: "dist/js/",
      baseUrl: "js/",
      mainConfigFile: "js/config.js",
      skipDirOptimize: true,
      preserveLicenseComments: false,
      generateSourceMaps: true,
      optimize: "uglify2",
      uglify2: {
        compress: {
          dead_code: true,
          drop_debugger: true,
          drop_console: false,
          global_defs: {
            DEBUG: false
          }
        }
      }
    },
  }
};
