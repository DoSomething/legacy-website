const $ = require('jquery');
import setting from '../utilities/Setting';
import Takeover from 'takeover/Takeover';

class OrganDonation extends Takeover {
  constructor($takeoverContainer) {

    super($takeoverContainer);

    this.zipCodeButton = this.$el.find('.submit-postal-code');
    this.registrationButton = this.$el.find('.submit-registration');
    this.backButton = this.$el.find('.takeover__screen .back-button');

    this.set();
  }

  /*
   * Handles the zip code request screen.
   */
  submitZipCode() {
    this.zipCodeButton.off('click');

    // Create custom deferred promise object.
    let ajaxPromise = $.Deferred().resolve().promise();

    this.zipCodeButton.click(e => {
      e.preventDefault();

      if (! this.$el.find('.validation__message.has-error').length) {
        const zipCode = this.$el.find('input[name="postal_code"]').val();
        // Make the ajax call, store the promise.
        const promise = this.sendRequest({
          'button' : this.zipCodeButton,
          'method' : 'GET',
          'url'    : `${this.baseUrl}/organ-donation/send-postal-code?postal_code=${zipCode}`,
        });

        // Fire done call backs in the order in which they were recieved.
        ajaxPromise = ajaxPromise.then(function() {
          return promise;
        }).done(function(data) {
          // @TODO - load next screen with this response data that tells us which fields we need to
          // show.
          console.log(data);
        });
      }
    });
  }

  /*
   * Handles the registration request screen.
   */
  submitRegistration() {
    this.registrationButton.off('click');
    const sid = setting('dosomethingSignup.sid');

    this.handleSubmit(this.registrationButton, {
      'button' : this.registrationButton,
      'method' : 'GET',
      'url'    : `${this.baseUrl}/organ-donation/registration`,
      'data'   : {
        'sid' : sid,
        'uid' : $('meta[name="drupal-user-id"]').attr('content')
      },
    });
  }

  /*
   * Handles back buttons.
   */
  goBack() {
    this.backButton.off('click');

    if (this.backButton.length) {
      this.backButton.click(e => {
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
    new OrganDonation($el);
  }
}
