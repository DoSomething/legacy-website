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
    this.$backButton         = this.$el.find('.takeover__screen .back-button');

    this.set();
  }

  /*
   * Handles the zip code request screen.
   */
  submitZipCode() {
    this.$zipCodeButton.off('click');

    // Create custom deferred promise object.
    let ajaxPromise = $.Deferred().resolve().promise();

    const _this = this;

    this.$zipCodeButton.click(e => {
      e.preventDefault();

      if (! this.$el.find('.validation__message.has-error').length) {
        const zipCode = this.$el.find('input[name="postal_code"]').val();
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
        });
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
  }

  getFieldMarkup(fieldsets) {
    let fieldMarkup = '';

    if (fieldsets) {
      console.log(fieldsets);

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
   * Handles back buttons.
   */
  goBack() {
    this.$backButton.off('click');

    if (this.$backButton.length) {
      this.$backButton.click(e => {
        e.preventDefault();

        this.changeScreens('previous');
      });
    }
  }

  /*
   * Sets up screen functionality.
   */
  set() {
    if (this.isActive($('.js-collect-zip-code'))) {
      this.submitZipCode();
    }

    if (this.isActive($('.js-collect-registration'))) {
      this.goBack();
      this.submitRegistration();
    }
  }
};

export default {
  init($el = $('.takeover-container')) {
    new OrganDonation($el, organDonationTpl);
  }
}
