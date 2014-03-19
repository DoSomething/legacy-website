/* jshint node:true */
"use strict";

module.exports = function(grunt) {
  grunt.initConfig({
    pkg: grunt.file.readJSON("package.json"),

    watch: {
      sass: {
        files: ["scss/**/*.{scss,sass}"],
        tasks: ["sass:compile"]
      },
      js: {
        files: ["js/**/*.js", "tests/**/*.js"],
        tasks: ["jshint:all", "browserify:dist", "uglify:dev"]
      },
      images: {
        files: ["assets/images/**/*.{png,jpg,jpeg,gif}"],
        tasks: ["imagemin"]
      },
      livereload: {
        files: ["dist/**/*.css", "dist/**/*.{js,json}", "dist/images/**/*.{png,jpg,jpeg,gif,webp,svg}"],
        options: {
          livereload: true
        }
      }
    },

    lintspaces: {
      js: {
        src: ["js/**/*.js"],
        options: {
          editorconfig: '.editorconfig'
        }
      },
      scss: {
        src: ["scss/**/*.scss"],
        options: {
          editorconfig: '.editorconfig'
        }
      }
    },

    sass: {
      compile: {
        files: {
          "dist/app.css": "scss/app.scss",
          "dist/ie.css": "scss/ie.scss"
        },
        options: {
          sourceComments: "normal"
        }
      }
    },

    cssmin: {
      minify: {
        options: {
          report: "gzip"
        },
        files: {
          "dist/app.css": ["dist/app.css"],
          "dist/ie.css": ["dist/ie.css"]
        }
      }
    },

    copy: {
      main: {
        files: [
          {expand: true, src: ["images/**"], dest: "dist/"},
        ]
      }
    },

    imagemin: {
      bundle: {
        files: [{
          expand: true,
          cwd: "assets/images/",
          src: ["**/*.{png,jpg,jpeg,gif}"],
          dest: "dist/assets/images"
        }]
      }
    },

    jshint: {
      options: {
        force: true,
        jshintrc: true,
        reporter: require("jshint-stylish")
      },
      all: ["js/**/*.js", "!js/vendor/**/*.js", "tests/**/*.js", "!tests/lib/**/*.js"]
    },

    qunit: {
      all: ["tests/*.html"]
    },

    browserify: {
      dist: {
        src: ['js/app.js'],
        dest: 'dist/app.js',
        options: {
          transform: ['debowerify']
        }
      }
    },

    uglify: {
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
    },

    docco: {
      docs: {
        src: ["js/*.js"],
        options: {
          output: "dist/docs"
        }
      }
    },

    shell: {
      scsslint: {
        command: "scss-lint ./scss --config ./.scss-lint.yaml",
        options: {
          stdout: true
        }
      },

      clean: {
        command: "rm -rf dist/*"
      }
    }

  });

  grunt.registerTask("default", ["build", "watch"]);

  // code linting
  grunt.registerTask("lint", ["jshint:all", "shell:scsslint", "lintspaces:js", "lintspaces:scss"]);

  // testing
  grunt.registerTask("test", ["test:css", "test:js"]);
  grunt.registerTask("test:css", ["shell:wraith"]);
  grunt.registerTask("test:js", ["qunit"]);

  // build
  grunt.registerTask("build", ["lint", "sass:compile", "browserify:dist", "uglify:dev", "copy:main"]);
  grunt.registerTask("prod", ["shell:clean", "sass:compile", "cssmin:minify", "copy:main", "browserify:dist", "uglify:prod"]); // used when preparing code for distribution

  grunt.loadNpmTasks("grunt-sass");
  grunt.loadNpmTasks("grunt-contrib-cssmin");
  grunt.loadNpmTasks("grunt-contrib-imagemin");
  grunt.loadNpmTasks("grunt-contrib-copy");
  grunt.loadNpmTasks("grunt-contrib-jshint");
  grunt.loadNpmTasks("grunt-contrib-qunit");
  grunt.loadNpmTasks('grunt-browserify');
  grunt.loadNpmTasks("grunt-contrib-uglify");
  grunt.loadNpmTasks("grunt-contrib-watch");
  grunt.loadNpmTasks("grunt-shell");
  grunt.loadNpmTasks('grunt-lintspaces');
};
