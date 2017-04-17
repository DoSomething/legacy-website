/* global Modernizr */

import ImageUploadFallback from '../images/ImageUploadFallback';
import reportbackTplSrc from 'reportback/templates/reportback.tpl.html';
import ImageUpload from '../images/ImageUpload';
import setting from '../utilities/Setting';
import { update } from '../utilities/LazyLoader';

const $ = require('jquery');
const debounce = require('lodash/debounce');
const template = require('lodash/template');
const forEach = require('lodash/forEach');

const Reportback = {

  $initialGallery: null,
  $extendedGallery: null,
  $viewMoreContainer: null,
  $viewMoreButton: null,
  $spinner: null,

  apiUrl: '/api/v1/reportback-items',

  reactions: {
    approved: setting('dsKudosReactions.approved'),
    terms: setting('dsKudosReactions.terms'),
    user: setting('dsKudosReactions.user', null),
  },

  nid: null,

  itemIds: null,

  itemsTotalRemaining: 0,

  requestSize: 12,

  inventory: [],

  inventoryIndex: 0,

  galleryInDom: false,

  adminAccess: null,

  uploader: null,

  /**
   * Initialize the Reportback interface.
   *
   * @param  {jQuery} $container  Reportback container object.
   */
  init: function($container = $('#reportback')) {
    if (!$container.length) return;

    this.reportbackContainer = $container;
    this.$reportbackWrapper = this.reportbackContainer.find('.wrapper:first');
    this.$reportbackForm = this.reportbackContainer.find('#dosomething-reportback-form');
    this.$uploadButton = this.reportbackContainer.find('.js-image-upload');
    this.$captionField = this.$reportbackForm.find('.form-item-caption');
    this.$initialGallery = $container.find('.gallery--reportback');

    this.nid = $container.data('nid');

    // Does the user have admin access?
    this.adminAccess = $container.data('admin');

    // IDs of collected Reportbacks in initial gallery.
    this.itemIds = $container.data('ids');

    // Total number of Reportbacks remaining to be displayed.
    this.itemsTotalRemaining = $container.data('remaining');
    if (this.itemsTotalRemaining > 0) {
      this.apiUrl = this.buildApiUrl();
      this.enableViewMore();
      this.enableResponsive();
    }

    if (Modernizr.filereader) {
      this.imageUploadInit();
    } else {
      ImageUploadFallback.init(this.$uploadButton, '.reportback__submissions');
    }
  },


  /**
   * Add the reportback entries to the DOM.
   * Adds the entire extended gallery if it does not exist already,
   * otherwise just appends the additional entries.
   */
  appendEntries: function() {
    const start = this.inventoryIndex;
    const end = this.inventory.length;
    let $cluster = $();

    for (let i = start; i < end; i++) {
      if (this.inventory[i] !== undefined) {
        $cluster = $cluster.add(this.inventory[i]);
      }
    }

    if (!this.galleryInDom) {
      this.insertGallery($cluster);
    } else {
      this.$extendedGallery.append($cluster);
    }

    this.inventoryIndex = this.inventoryIndex + (end - start);

    // Lazy-load newly added images.
    update();
  },


  /**
   * Build out the API URL with the campaign node id.
   *
   * @return {string}  API base url.
   */
  buildApiUrl: function() {
    return `${this.apiUrl}?campaigns=${this.nid}&status=promoted,approved&exclude=${this.itemIds}&count=${this.requestSize}`;
  },


  /**
   * Remove the View More button.
   */
  disableViewMore: function() {
    this.$viewMoreButton.remove();
  },


  /**
   * Enable Media Query check to shift around markup.
   */
  enableResponsive: function() {
    const _this = this;

    $(window).on('resize', debounce(function() {
      if (_this.isLargerMedia()) {
        if (_this.$viewMoreContainer) {
          _this.$viewMoreContainer.detach();
          _this.$viewMoreContainer.insertAfter(_this.$reportbackWrapper);
        }
      } else {
        if (_this.$viewMoreContainer) {
          _this.$viewMoreContainer.detach();
          _this.$viewMoreContainer.insertAfter(_this.$initialGallery);
        }
      }
    }, 300));
  },


  /**
   * Add the View More button if there are additional reportbacks.
   */
  enableViewMore: function() {
    const _this = this;
    const buttonText = Drupal.t('View more');

    this.$viewMoreContainer = $(`<div class="reportback__view-more"></div>`);
    this.$viewMoreButton = $(`<button id="view-more-button" class="button button--view-more -tertiary inline-alt-text-color ga-click" data-track-category="Gallery" data-track-action="click" data-track-label="View More Clicks">${buttonText}</button>`);

    this.$viewMoreContainer.append(this.$viewMoreButton);

    if (this.isLargerMedia()) {
      this.$viewMoreContainer.insertAfter(this.$reportbackWrapper);
    } else {
      this.$viewMoreContainer.insertAfter(this.$initialGallery);
    }

    this.$viewMoreButton.on('click', function() {
      _this.request();
    });
  },

  /**
   * Get Kudos Reactions for a Reportback item.
   *
   * @param  {array} data  Array of Kudos objects from API.
   * @return {array}
   */
    getReactions: function(data) {
      let reactions = [];

      forEach(this.reactions.approved, (term) => {
        const termId = this.reactions.terms[term];

        let reaction = {
          kudosId: null,
          term: term,
          termId: termId,
          total: 0,
          userReacted: false,
        };

        if (data.length) {
          forEach(data, (record) => {
            if (record.term.name === term) {
              reaction.kudosId = record.current_user.kudos_id;
              reaction.term = record.term.name;
              reaction.termId = record.term.id;
              reaction.total = record.term.total;
              reaction.userReacted = record.current_user.reacted;
            }
          });
        } else {
          reaction.kudosId = null;
          reaction.term = data.term.name;
          reaction.termId = data.term.id;
          reaction.total = data.term.total;
          reaction.userReacted = data.current_user.reacted;
        }

        reactions.push(reaction);
      });

    return reactions;
  },

  /**
   * Initialize the ImageUpload interface.
   */
  imageUploadInit: function() {
    this.uploader = new ImageUpload(this.$uploadButton);

    this.$captionField.hide();
  },


  /**
   * Insert the extended gallery into the DOM.
   *
   * @param  {string} data  Markup of list items.
   */
  insertGallery: function(data) {
    const content = data || null;

    this.$extendedGallery = $(`<ul class="gallery gallery--extended"></ul>`);

    if (content) {
      this.$extendedGallery.html(content);
    }

    this.$viewMoreContainer.prepend(this.$extendedGallery);

    this.galleryInDom = true;
  },


  /**
   * Check to see if media size is large.
   *
   * @return {boolean} true is large media
   */
  isLargerMedia: function() {
    return ($(window).outerWidth() >= 760);
  },


  /**
   * Ajax request to retrieve more Reportback entries.
   */
  request: function() {
    const _this = this;

    $.ajax({
      url: this.apiUrl,
      dataType: 'json',
      beforeSend: function() {
        if (_this.$spinner) {
          _this.$spinner.show();
        } else {
          _this.$spinner = $(`<div class="spinner"></div>`);
          _this.$viewMoreContainer.append(_this.$spinner);
        }
      },
    }).done(function(response) {
        if (response.meta.pagination.links.next) {
          var splitResponseUrl = response.meta.pagination.links.next.split("&");
          var urlParts = this.url.split("&");
          var pageParts = urlParts[urlParts.length-1].split("=");
          if (pageParts[0] === "page") {
            if (splitResponseUrl) {
              var urlWithoutPageNumber = (this.url).slice(0, -1);
              _this.apiUrl = urlWithoutPageNumber.concat(pageParts[1]);
            }
          } else {
              _this.apiUrl = (this.url).concat("&").concat(splitResponseUrl[splitResponseUrl.length-1]);
          }
      } else if (response.meta.pagination.links.next_uri) {
        _this.apiUrl = response.meta.pagination.links.next_uri;
      } else {
        _this.apiUrl = null;
      }

      _this.templatize(response);

      _this.$spinner.hide();

      _this.appendEntries();
    }).fail(function() {
      // @TODO: handle error here!
    }).always(function() {
      if (!_this.apiUrl) {
        _this.disableViewMore();
      }
    });
  },


  /**
   * Use specified template to markup each reportback entry list item.
   *
   * @param {array} collection JSON object containing reportback items and other meta data.
   */
  templatize: function(collection) {
    const items = collection.data;

    for (let i = 0, count = items.length; i < count; i++) {
      const data = {
        'id': items[i].id,
        'reportbackId': items[i].reportback.id,
        'image': items[i].media.uri,
        'caption': items[i].caption,
        'status': items[i].status,
        'isListItem': true,  // @TODO: probably a better way to address this... :insert shruggy emoji here:
        'reactions': {
          enabled: setting('dsKudosReactions.enabled'),
          data: this.getReactions(items[i].kudos.data),
        }
      };

      data.adminLink = this.adminAccess ? `/admin/reportback/${items[i].reportback.id}` : false;

      const markup = template(reportbackTplSrc);

      this.inventory.push(markup(data));
    }
  },

};

export default Reportback;
