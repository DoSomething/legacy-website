const $ = require('jquery');
const forEach = require('lodash/collection/forEach');
const template = require('lodash/string/template');

import setting from '../utilities/Setting';
import Takeover from 'takeover/Takeover';
import Validation from 'dosomething-validation';

// Field template.
import fieldTpl from 'campaign/templates/OrganDonation/field.tpl.html';

class OrganDonation extends Takeover {
  constructor($takeoverContainer, tpl) {

    super($takeoverContainer, tpl);

    this.postalCodeUrl        = `${this.baseUrl}/organize/postal-code`;
    this.registrationUrl      = `${this.baseUrl}/organize/registration`;
    this.storeRegistrationUrl = `${this.baseUrl}/organ-donation/registration`;
    this.userInfo             = setting('dosomethingUser.userInfo');
    this.sid                  = setting('dosomethingSignup.sid');
    this.$zipCodeButton       = this.$el.find('.submit-postal-code');
    this.$zipCodeScreen       = this.$el.find('.js-collect-zip-code');
    this.$registrationScreen  = this.$el.find('.js-collect-registration');
    this.$shareScreen         = this.$el.find('.js-share-confirmation');
    this.$errorContainer      = this.$el.find('.js-organize-errors');

    this.loadScreen(this.$zipCodeScreen);
    this.set();
  }

  /*
   * Handles the zip code request screen.
   */
  loadZipCode() {
    this.loadScreen(this.$zipCodeScreen);

    const $zipCodeButton = this.$el.find('.submit-postal-code');

    $zipCodeButton.click(e => {
      e.preventDefault();

      const $zipCodeField = this.$el.find('input[name="postal_code"]');
      const zipCode = $zipCodeField.val();

      if (zipCode !== '' && !$zipCodeField.hasClass('has-error')) {

        this.toggleSpinner($zipCodeButton);

        this.sendRequest({
          url    : `${this.postalCodeUrl}?postal_code=${zipCode}`,
          method : 'GET',
        })
        .then(json => {
          if (json.accepts_registration === true) {
            this.loadRegistration(json, zipCode);
          } else if (typeof json.error !== 'undefined') {
            this.showValidationMessage($zipCodeField, 'Something went wrong on our end, please try again later');
            this.set();
          } else {
            this.showValidationMessage($zipCodeField, 'Zip Code Not Found.');
            this.set();
          }

          this.toggleSpinner($zipCodeButton);
        });
      } else {
        this.showValidationMessage($zipCodeField, 'Please enter a zip.');
      }
    });

    this.resizeContainerHeight(this.$el.find('.takeover'), this.$zipCodeScreen);
  }

  /*
   * Handles the registration request screen.
   */
  loadRegistration(formConfig, zipCode) {
    this.loadScreen(this.$registrationScreen);

    const $registrationButton = this.$el.find('.submit-registration');
    const $registrationButtonCopy = this.$el.find('.submit-registration');
    const $registrationForm = this.$el.find('.organize-registration-form');

    this.$registrationScreen.find('.js-form-fields').html('');

    formConfig.registration_configuration.forEach(config => {
      if (config.fieldsets[0]) {
        this.$registrationScreen.find('.js-form-fields').append('<h4>' + config.title + '</h4>');

        const fieldMarkup = this.getFieldMarkup(config.fieldsets[0], zipCode);

        this.$registrationScreen.find('.js-form-fields').append(fieldMarkup);
      }
    });

    this.prepareFieldValidation(this.$el.find('.js-collect-registration').find(".registration-value"));

    // Sorta a hack, the Validation package adds a submit handler to forms on the page to kick off validation
    // this just highjacks that handler and tells it not to refresh the page since we need to handle succesful
    // validation our own way.
    $('body').submit(e => {
      return false;
    });

    // Send the actual request, if ds validation has passed.
    Validation.Events.subscribe('Validation:Submitted', (topic, args) => {
      const values = $registrationForm.serialize();

      this.toggleSpinner($registrationButton);

      this.sendRequest({
        url    : `${this.registrationUrl}?${values}`,
        method : 'GET',
      })
      .then(json => {
        if (typeof json.uuid !== 'undefined') {
          this.loadShare();
          this.set()
        } else if (typeof json.error !== 'undefined') {
          this.toggleSpinner($registrationButton);

          $('<div class="validation__message has-error">Something went wrong on our end, please try again later.</div>').insertBefore($registrationButton);
        } else {
          $registrationButton.removeClass('is-loading');
          $registrationButton.removeAttr('disabled');

          this.toggleSpinner($registrationButton);

          // Display any errors we get back from Organize.
          this.$errorContainer.html('');

          this.$errorContainer.append('<div class="validation__message has-error"><strong>There were some errors with your form:</strong></div><ul>');

          for (let error in json) {
            if (json.hasOwnProperty(error)) {
              if (error === 'agree_to_tos') {
                this.$errorContainer.append('<li class="validation__message has-error">You must agree to the terms of service</li>');
              } else {
                this.$errorContainer.append('<li class="validation__message has-error">' + json[error] + '</li>');
              }
            }
          }

          this.$errorContainer.append('</ul>');

          this.resizeContainerHeight(this.$el.find('.takeover'), this.$registrationScreen);
        }
      });
    });

    this.goBack();

    this.resizeContainerHeight(this.$el.find('.takeover'), this.$registrationScreen);
  }

  /*
   * Handles the share/confirmation screen.
   */
  loadShare() {
    this.loadScreen(this.$shareScreen);

    // @TODO - Handle submission of "done" button that posts to our db info about the submission being done.
    // This happens whether they hit "done" or "skip" since at this point those are the same
    const sid = this.sid;

    this.sendRequest({
      url    : `${this.storeRegistrationUrl}?sid=${sid}&uid=${this.userInfo['uid']}`,
      method : 'GET',
    });

    this.resizeContainerHeight(this.$el.find('.takeover'), this.$shareScreen);
  }

  /*
   * Get the compiled markup of all the fields needed.
   */
  getFieldMarkup(fieldsets, zipCode) {
    let fieldMarkup = '';

    const fieldToValidationMap = new Map([
      ['email'            , 'email'],
      ['first_name'       , 'organ_first_name'],
      ['last_name'        , 'organ_last_name'],
      ['gender'           , 'gender'],
      ['birthdate'        , 'birthday'],
      ['street_address'   , 'address1'],
      ['street_address_2' , 'address2'],
      ['city'             , 'city'],
      ['state'            , 'state'],
      ['postal_code'      , 'organ_zipcode'],
      ['ssn'              , 'organ_ssn'],
    ]);

    if (fieldsets) {
      fieldsets.fields.forEach(field => {
        for (const entry of fieldToValidationMap.entries()) {
          if (field.field_name === entry[0]) {
            field.validate = true;
            field.validation_name = entry[1];
            if (field.field_name === 'postal_code') {
              field.pre_fill_value = zipCode;
            } else if (field.field_name in this.userInfo) {
              field.pre_fill_value = this.userInfo[field.field_name];
            }
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

    // this.prepareFieldValidation(this.$el.find("[data-validate]"));
  }
};

export default {
  init($el = $('.takeover-container')) {
    new OrganDonation($el);
  }
}
