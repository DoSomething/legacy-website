/*
 * Configuration options for PhantomCSS.
 */

var phantomcss = require(ROOT + '/node_modules/phantomcss/phantomcss');

function formattedFilename(test) {
  return test.filename.replace(ROOT + "/tests/visual/", "").replace(".png", "");
}

phantomcss.init({
  libraryRoot: ROOT + '/node_modules/phantomcss',
  screenshotRoot: ROOT + '/tests/visual',
  failedComparisonsRoot: ROOT + '/tests/visual/failures',
  addLabelToFailedImage: false,
  mismatchTolerance: 2.00,
  onPass: function(test) {
    casper.test.pass('No changes found for visual regression test "' + formattedFilename(test) + '".');
  },
  onFail: function(test) {
    casper.test.fail('Visual change found in "' + formattedFilename(test) + '" (' + test.mismatch + '% mismatch)');
  },
  onNewImage: function(test) {
    casper.test.info('New baseline screenshot generated at "'+ formattedFilename(test) + '".');
  },
  onComplete: function(tests, noOfFails, noOfErrors) {
    if( tests.length === 0){
      casper.test.info("No tests run.");
    } else {
      if(noOfFails !== 0) {
        casper.test.info("Visual diffs generated in 'tests/visual/failures' for failing tests.");
        casper.test.info("If changes are expected, replace testName.png with testName.fail.png to \"merge\" the changes so that future tests pass, and commit the updated test image.");
      }
    }
  },
  fileNameGetter: function(root,filename){ 
    var expected = root + fs.separator + filename + '.png';
    var diff = root + fs.separator + filename + '.diff.png';
    if(fs.isFile(expected)){
      return diff;
    } else {
      return expected;
    }
  },
  outputSettings: {
    errorColor: {
      red: 255,
      green: 0,
      blue: 255
    },
    errorType: 'movement',
    transparency: 0.3,
    largeImageThreshold: 1440
  }
});
