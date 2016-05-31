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

  submitZipCode() {
    this.zipCodeButton.off('click');

    if ($('.submit-button-container').find('.spinner').length) {
      $('.submit-button-container').html(this.zipCodeButton);
    }

    this.handleSubmit(this.zipCodeButton, {
      'button' : this.zipCodeButton,
      'method' : 'GET',
      'url'    : 'http://jsonplaceholder.typicode.com/posts/1',
      'data'   : null,
    });
  }

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
    if ($('.js-collect-zip-code').hasClass(this.activeClass)) {
      this.submitZipCode();
    }

    if ($('.js-collect-registration').hasClass(this.activeClass)) {
      this.goBack();
      this.submitRegistration();
    }
  }
};

export default OrganDonation;
