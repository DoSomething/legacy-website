/**
 * @file
 * Variables shared between all CasperJS tests.
 */

// Set current working directory to variable
var ROOT = require('system').env['PWD'];

// Define the URL for all tests.
var url = casper.cli.get('url');

// Reference testing campaign node on staging DB.
var CAMPAIGN = {
  nid: 1485,
  url: url + "/node/" + 1485,
  data: require(ROOT + "/tests/fixtures/campaign.json")
}

// Save any static strings that are used in multiple tests.
var CAMPAIGN_SIGNUP_MESSAGE = "You're signed up for";
