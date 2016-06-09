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

    this.postalCodeUrl       = `${this.baseUrl}/organize/postal-code`;
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

    this.$zipCodeButton.click(e => {
      e.preventDefault();

      const $zipCodeField = this.$el.find('input[name="postal_code"]');

      const zipCode = $zipCodeField.val();

      if (zipCode || $zipCodeField.hasClass('has-error')) {
        fetch(`${this.postalCodeUrl}?postal_code=${zipCode}`, {
          method: 'GET',
          credentials: 'same-origin',
          headers: {
            'X-CSRF-Token': $('meta[name="csrf-token"]').attr('content')
          }
        })
        .then(response => response.json())
        .then(json => {
          if (json.accepts_registration === true) {
            this.loadRegistration(json);
          } else {
            this.showValidationMessage($zipCodeField, 'Zip Code Not Found.');
            this.set();
          }
        });
      } else {
        this.showValidationMessage($zipCodeField, 'Please enter a zip.');
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

  /*
   * Get the compiled markup of all the fields needed.
   */
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
