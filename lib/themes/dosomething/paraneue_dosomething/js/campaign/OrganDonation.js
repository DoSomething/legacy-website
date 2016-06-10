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
    this.$zipCodeScreen      = this.$el.find('.js-collect-zip-code');
    this.$registrationScreen = this.$el.find('.js-collect-registration');

    this.loadScreen(this.$zipCodeScreen);
    this.set();
    this.prepareFieldValidation($('input'));
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

        this.toggleSpinner(this.$zipCodeButton);

        this.sendRequest({
          url    : `${this.postalCodeUrl}?postal_code=${zipCode}`,
          method : 'GET',
          done   : json => {
            if (json.accepts_registration === true) {
              this.loadRegistration(json);
            } else if (json.error !== null) {
              this.showValidationMessage($zipCodeField, 'Something went wrong on our end, please try again later');
              this.set();
            } else {
              this.showValidationMessage($zipCodeField, 'Zip Code Not Found.');
              this.set();
            }

            this.toggleSpinner(this.$zipCodeButton);
          }
        });
      } else {
        this.showValidationMessage($zipCodeField, 'Please enter a zip.');
      }
    });

    // @TODO - temporary hack. Should try doing this with better CSS animations using margins
    // instead of absolutly positioned elements that are out of the flow of the page.
    this.resizeContainerHeight(this.$el.find('.takeover'), this.$zipCodeScreen, null);
  }

  /*
   * Handles the registration request screen.
   */
  loadRegistration(formConfig) {
    this.$registrationButton.off('click');

    this.loadScreen(this.$registrationScreen);
    this.addTemplate(this.$registrationScreen, registrationTpl, formConfig);

    formConfig.registration_configuration.forEach(config => {
      if (config.fieldsets[0]) {
        this.$registrationScreen.find('.js-form-fields').append('<h4>' + config.title + '</h4>');

        const fieldMarkup = this.getFieldMarkup(config.fieldsets[0]);

        this.$registrationScreen.find('.js-form-fields').append(fieldMarkup);
      }
    });

    // @TODO - handle form submission.

    this.goBack();

    // @TODO - temporary hack. Should try doing this with better CSS animations using margins
    // instead of absolutly positions elements that are out of the flow of the page.
    this.resizeContainerHeight(this.$el.find('.takeover'), $registrationScreen, null);
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
    if (this.isActive(this.$zipCodeScreen)) {
      this.loadZipCode();
    }

    if (this.isActive(this.$registrationScreen)) {
      this.loadRegistration();
    }
  }
};

export default {
  init($el = $('.takeover-container')) {
    new OrganDonation($el, organDonationTpl);
  }
}
