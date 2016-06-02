const $ = require('jquery');
import setting from '../utilities/Setting';
import Takeover from 'takeover/Takeover';

class OrganDonation extends Takeover {
  constructor($takeoverContainer) {

    super($takeoverContainer);

    this.zipCodeButton = $('.submit-postal-code');
    this.registrationButton = $('.submit-registration');
    this.backButton = $('.takeover__screen .back-button');

    this.set();
  }

  /*
   * Handles the zip code request screen.
   */
  submitZipCode() {
    this.zipCodeButton.off('click');

    // if ($('.submit-button-container').find('.spinner').length) {
    //   $('.submit-button-container').html(this.zipCodeButton);
    // }

    // @TODO - currently submits to fake endpoint.
    this.handleSubmit(this.zipCodeButton, {
      'button' : this.zipCodeButton,
      'method' : 'GET',
      'url'    : 'http://jsonplaceholder.typicode.com/posts/1',
      'data'   : null,
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
      'url'    : this.baseUrl + '/organ-donation/registration',
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

export default OrganDonation;
