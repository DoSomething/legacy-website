const $ = require('jquery');
const forEach = require('lodash/collection/forEach');
const template = require('lodash/string/template');

import setting from '../utilities/Setting';
import Takeover from 'takeover/Takeover';

// Field template.
import fieldTpl from 'campaign/templates/OrganDonation/field.tpl.html';

class OrganDonation extends Takeover {
  constructor($takeoverContainer, tpl) {

    super($takeoverContainer, tpl);

    this.postalCodeUrl       = `${this.baseUrl}/organize/postal-code`;
    this.registrationUrl     = `${this.baseUrl}/organize/registration`;
    this.sid                 = setting('dosomethingSignup.sid');
    this.$zipCodeButton      = this.$el.find('.submit-postal-code');
    this.$zipCodeScreen      = this.$el.find('.js-collect-zip-code');
    this.$registrationScreen = this.$el.find('.js-collect-registration');
    this.$shareScreen        = this.$el.find('.js-share-confirmation');

    this.loadScreen(this.$zipCodeScreen);
    this.set();
  }

  /*
   * Handles the zip code request screen.
   */
  loadZipCode() {
    this.loadScreen(this.$zipCodeScreen);
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
        })
        .then(json => {
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
        });
      } else {
        this.showValidationMessage($zipCodeField, 'Please enter a zip.');
      }
    });

    // @TODO - temporary hack. Should try doing this with better CSS animations using margins
    // instead of absolutly positioned elements that are out of the flow of the page.
    this.resizeContainerHeight(this.$el.find('.takeover'), this.$zipCodeScreen);
  }

  /*
   * Handles the registration request screen.
   */
  loadRegistration(formConfig) {
    this.loadScreen(this.$registrationScreen);

    const $registrationButton = this.$el.find('.submit-registration');
    const $registrationForm = this.$el.find('.organize-registration-form');

    this.$registrationScreen.find('.js-form-fields').html('');

    formConfig.registration_configuration.forEach(config => {
      if (config.fieldsets[0]) {
        this.$registrationScreen.find('.js-form-fields').append('<h4>' + config.title + '</h4>');

        const fieldMarkup = this.getFieldMarkup(config.fieldsets[0]);

        this.$registrationScreen.find('.js-form-fields').append(fieldMarkup);
      }
    });

    $registrationButton.click(e => {
      e.preventDefault();

      // Grab all fields, and all field values.
      const values = $registrationForm.serialize();

      // // Add spinner.
      this.toggleSpinner($registrationButton);

      // Send the actual request.
      // @TODO - only do this if there are no frontend validation errors.
      this.sendRequest({
        url    : `${this.registrationUrl}?${values}`,
        method : 'GET',
      })
      .then(json => {
        if (typeof json.uuid !== 'uuid') {
          this.loadShare();
          this.set()
        }
        // @TODO - handle errors.

        this.toggleSpinner($registrationButton);
      });
    });

    this.goBack();

    // @TODO - temporary hack. Should try doing this with better CSS animations using margins
    // instead of absolutly positions elements that are out of the flow of the page.
    this.resizeContainerHeight(this.$el.find('.takeover'), this.$registrationScreen);

    this.prepareFieldValidation(this.$el.find('input'));
  }

  /*
   * Handles the share/confirmation screen.
   */
  loadShare() {
    this.loadScreen(this.$shareScreen);

    // @TODO - Handle submission of "done" button that posts to our db info about the submission being done.

    this.resizeContainerHeight(this.$el.find('.takeover'), this.$shareScreen);
  }

  /*
   * Get the compiled markup of all the fields needed.
   */
  getFieldMarkup(fieldsets) {
    let fieldMarkup = '';

    const fieldToValidationMap = new Map([
      ['email'            , 'email'],
      ['first_name'       , 'fname'],
      ['last_name'        , 'lname'],
      ['middle_name'      , 'middle_name'],
      ['last_name'        , 'lname'],
      ['gender'           , 'gender'],
      ['birthdate'        , 'birthday'],
      ['street_address'   , 'address1'],
      ['street_address_2' , 'address2'],
      ['city'             , 'city'],
      ['state'            , 'state'],
      ['postal_code'      , 'zipcode'],
    ]);

    if (fieldsets) {
      fieldsets.fields.forEach(field => {
        // @TODO - better iteration http://stackoverflow.com/questions/31084619/map-a-javascript-es6-map
        for (const entry of fieldToValidationMap.entries()) {
          if (field.field_name === entry[0]) {
            field.validate = true;
            field.validation_name = entry[1];
          }
        }

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

    if (this.isActive(this.$shareScreen)) {
      this.loadShare();
    }

    this.prepareFieldValidation(this.$el.find('input'));
  }
};

export default {
  init($el = $('.takeover-container')) {
    new OrganDonation($el);
  }
}
