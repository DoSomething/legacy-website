const $ = require('jquery');
const forEach = require('lodash/collection/forEach');
const template = require('lodash/string/template');

import setting from '../utilities/Setting';
import Takeover from 'takeover/Takeover';

// Templates
import organDonationTpl from 'campaign/templates/OrganDonation/takeover.tpl.html';
import registrationTpl from 'campaign/templates/OrganDonation/registration.tpl.html';
import fieldTpl from 'campaign/templates/OrganDonation/field.tpl.html';

class OrganDonation extends Takeover {
  constructor($takeoverContainer, tpl) {

    super($takeoverContainer, tpl);

    this.sid                 = setting('dosomethingSignup.sid');
    this.$zipCodeButton      = this.$el.find('.submit-postal-code');
    this.$registrationButton = this.$el.find('.submit-registration');

    this.set();
  }

  /*
   * Handles the zip code request screen.
   */
  loadZipCode() {
    this.$zipCodeButton.off('click');

    // Create custom deferred promise object.
    let ajaxPromise = $.Deferred().resolve().promise();

    const _this = this;

    this.$zipCodeButton.click(e => {
      e.preventDefault();

      const $zipCodeField = this.$el.find('input[name="postal_code"]');

      const zipCode = $zipCodeField.val();

      if (zipCode || $zipCodeField.hasClass('has-error')) {
        // Make the ajax call, store the promise.
        const promise = this.sendRequest({
          'button' : this.$zipCodeButton,
          'method' : 'GET',
          'url'    : `${this.baseUrl}/organ-donation/send-postal-code?postal_code=${zipCode}`,
        });

        // Fire done call backs in the order in which they were recieved.
        ajaxPromise = ajaxPromise.then(function() {
          return promise;
        }).done(function(data) {
          _this.loadRegistration(data);
        }).fail(function(data) {
          // @TODO - Do something more useful here. There was an error on the API side and we
          // should probably check what it was specifically. Probably, the zip was not found.
          // Validation.showValidationMessage($zipCodeField, {message: 'Zip Code Not Found'});
          _this.showValidationMessage($zipCodeField, 'Zip Code Not Found.');

          _this.set();
        });
      } else {
        // Validation.showValidationMessage($zipCodeField, {message: 'Please enter a zip code'});
        _this.showValidationMessage($zipCodeField, 'Please enter a zip.');
      }
    });
  }

  /*
   * Handles the registration request screen.
   */
  loadRegistration(formConfig) {
    const $registrationScreen = $('.js-collect-registration');

    this.$registrationButton.off('click');

    this.loadScreen($registrationScreen);
    this.addTemplate($registrationScreen, registrationTpl, formConfig);

    formConfig.registration_configuration.forEach(config => {
      if (config.fieldsets[0]) {
        $registrationScreen.find('.js-form-fields').append('<h4>' + config.title + '</h4>');

        const fieldMarkup = this.getFieldMarkup(config.fieldsets[0]);

        $registrationScreen.find('.js-form-fields').append(fieldMarkup);
      }
    });

    this.handleSubmit(this.$registrationButton, {
      'button' : this.$registrationButton,
      'method' : 'GET',
      'url'    : `${this.baseUrl}/organ-donation/registration`,
      'data'   : {
        'sid' : this.sid,
        'uid' : $('meta[name="drupal-user-id"]').attr('content')
      },
    });

    this.goBack();
  }

  getFieldMarkup(fieldsets) {
    let fieldMarkup = '';

    if (fieldsets) {
      fieldsets.fields.forEach(field => {
        const fieldTemplate = template(fieldTpl);

        fieldMarkup = fieldMarkup + fieldTemplate(field);
      });
    }

    return fieldMarkup;
  }

  loadScreen($screen) {
    this.$el.find(`.takeover__screen.${this.activeClass}`).removeClass(this.activeClass);
    $screen.addClass(this.activeClass);
  }

  addTemplate($container, tpl, data) {
    data = (data) ? data : {};

    const markup = template(tpl);

    $container.html(markup(data))
  }

  /*
   * Sets up screen functionality.
   */
  set() {
    if (this.isActive($('.js-collect-zip-code'))) {
      this.loadZipCode();
    }

    if (this.isActive($('.js-collect-registration'))) {
      this.loadRegistration();
    }
  }
};

export default {
  init($el = $('.takeover-container')) {
    new OrganDonation($el, organDonationTpl);
  }
}
