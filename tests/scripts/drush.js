/**
 * @file
 * Allow CasperJS tests to interact with local Drush installation.
 */

/**
 * Check if given object is an array.
 * @returns {boolean} If true, object is an array.
 */
var isArray = function(obj) {
  return Object.prototype.toString.call(obj) === '[object Array]';
}

/**
 * Execute a Drush command.
 * Adapted from https://bitbucket.org/davereid/drush-casperjs/
 *
 * @param command
 *   The drush command to execute. For simple commands that require no arguments
 *   this can be a string. For complex commands that require arguments this
 *   should be an array where each element is a part of the command. e.g.)
 *   ['pm-info', 'overlay', '--yes'].
 *
 * @returns mixed
 *   Either the output to stdOut from the drush command or false if the
 *   command failed.
 */
casper.drush = function(command, json) {
  var spawn;

  // Make sure we can load the required child_process library from PhantomJS.
  try {
    spawn = require("child_process").spawn;
  } catch (e) {
    this.log(e, "error");
  }

  if (spawn) {
    var is_finished = false;
    var error = false;
    var output;

    // Prepare our command by making sure it's in the appropriate format for the
    // spawn executor.
    if (!isArray(command)) {
      command = [command];
    }

    if(json === true) {
      command.push("--format=json");
    }
    command.push("--uri=" + url);

    var DIRECTORY = ROOT + "/html";
    this.log("Running Drush command in " + DIRECTORY + ": " + command.join(' '));

    fs.changeWorkingDirectory(DIRECTORY);
    var child = spawn("drush", command);

    child.stdout.on("data", function (data) {
      casper.log("Drush command successful.");
      output = data;
    });

    child.stderr.on("data", function (data) {
      // There was an error executing the command so just return false.
      casper.log("Drush has encountered an error: " + data, "warning");

      return false;
    });

    child.on("exit", function (code) {
      // Finished the Drush command.
      casper.log("Drush command exited with code: " + code, "debug");
      is_finished = true;
    });

    while (!is_finished) {
      // Do nothing, just block and wait for Drush to do it's thing.
    }

    this.log("Drush command output: " + output);

    if(json && typeof output !== "undefined") {
      output = JSON.parse(output);
    }

    return output;
  }

  return false;
};

