// Set current working directory to variable
var ROOT = require('system').env['PWD'];

// Define the url for all tests.
var url = casper.cli.get('url');

// Set default viewport for all tests.
casper.options.viewportSize = { width: 1280, height: 1024 };

var CAMPAIGN_NID = 1001;

// Set some static strings
var CAMPAIGN_SIGNUP_MESSAGE = "You're signed up for";
