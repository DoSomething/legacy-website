/**
 * This is where we load and initialize components of our app.
 */

import $ from 'jquery';

// DoSomething.org modules
import '@dosomething/forge';
import Validation from 'dosomething-validation';
import Modal from 'dosomething-modal';

// Styles
import '../scss/app.scss';

// Attach Validation & Modal to the window so `<script>` tags can use it.
window.DSValidation = Validation;
window.DSModal = Modal;

// Modules
import Donate from 'donate/Donate';
import Finder from 'finder/Finder';
import Reportback from 'reportback/Reportback';
import SchoolFinder from 'campaign/SchoolFinder';

// Patterns
import Gallery from 'patterns/Gallery';
import Tile from 'patterns/Tile';

// Utilities
import Analytics from 'utilities/Analytics';
import Share from 'utilities/Share';
import ShowMore from 'utilities/ShowMore';
import LazyLoader from 'utilities/LazyLoader';
import Globe from 'utilities/Globe';

// Load validation rules
import 'validators/auth';
import 'validators/reportback';
import 'validators/address';
import 'validators/donate';

import 'campaign/prototype';

// Initialize analytics.
Analytics.init();

/**
 * Let's go!
 */
$(document).ready(function() {
  /**
   * Initialize feature modules. Each module is responsible for checking if
   * it exists on the page, and short-circuiting if not.
   */

  // Ping the dashboard with my location
  Globe.init();

  // Initialize the donation form on the donate page.
  Donate.init();

  // Initialize the campaign finder on the homepage.
  Finder.init();

  // Initialize any galleries with Swapper or Revealer enhancements.
  Gallery.init();

  // Initialize image lazy loading.
  LazyLoader.init();

  // Initialize Reportback interface if on the action page.
  Reportback.init();

  // Initialize School Finder if it is on the page.
  SchoolFinder.init();

  // Initialize any share dialogs.
  Share.init();

  // Initialize "show more" button on permalink pages.
  ShowMore.init();

  // Add fallback for HTML5 video on mobile tiles
  Tile.init();


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
