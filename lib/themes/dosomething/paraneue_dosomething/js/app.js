/**
 * This is where we load and initialize components of our app.
 */

import $ from 'jquery';

// DoSomething.org modules
import 'dosomething-neue';
import Validation from 'dosomething-validation';
import Modal from 'dosomething-modal';

// Attach Validation & Modal to the window so `<script>` tags can use it.
window.DSValidation = Validation;
window.DSModal = Modal;

// Modules
import Finder from 'finder/Finder';
import Donate from 'donate/Donate';
import Reportback from 'reportback/Reportback';
import HotModule from 'campaign/HotModule';
import 'campaign/SchoolFinder';

// Utilities
import Share from 'utilities/share';
import ShowMore from 'utilities/show-more';
import 'utilities/analytics';

// Patterns
import 'patterns/tiles';
import Gallery from 'patterns/gallery';

// Load validation rules
import 'validators/auth';
import 'validators/reportback';
import 'validators/address';
import 'validators/donate';

/**
 * Let's go!
 */
$(document).ready(function() {

  /**
   * Initialize feature modules. Each module is responsible for checking if
   * it exists on the page, and short-circuiting if not.
   */

  // Initialize the campaign finder on the homepage.
  Finder.init();

  // Initialize the donation form on the donate page.
  Donate.init();

  // Initialize any galleries with Swapper or Revealer enhancements.
  Gallery.init();

  // Initialize any share dialogs.
  Share.init();

  // Initialize "show more" button on permalink pages.
  ShowMore.init();

  // Initialize the hot module, if it is toggled on.
  HotModule.init();

  // Initialize Reportback interface if on the action page.
  Reportback.init();

  /**
   * We use the Filament Group's fixed-sticky library to polyfill the
   * CSS `position: sticky` property.
   *
   * Any elements that should "stick" to an edge of the browser on scroll should have
   * both the `position: sticky` property for supported browsers, and the `.js-fixedsticky`
   * class to trigger the polyfill for environments without native support.
   *
   * @see https://github.com/filamentgroup/fixed-sticky
   */
  $('.js-fixedsticky').fixedsticky();

  /**
   * Add a `.js-ready` class to the page to indicate that we're done
   * initializing the client-side interface.
   */
  $('html').addClass('js-ready');

});
