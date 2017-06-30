import $ from 'jquery';
import setting from '../utilities/Setting';
import ApiClient from '../utilities/ApiClient';

function prefillForm($form) {
  $form.find('#addr-street1').val(setting('dsUser.info.addr_street1'));
  $form.find('#addr-street2').val(setting('dsUser.info.addr_street2'));
  $form.find('#addr-city').val(setting('dsUser.info.addr_city'));
  $form.find('#addr-state').val(setting('dsUser.info.addr_state'));
  $form.find('#addr-zip').val(setting('dsUser.info.addr_zip'));
}

function handleFormSubmit($form, callback) {
  $form.on('submit', (event) => {
    event.preventDefault();

    const payload = {
      'addr-street1': $form.find('#addr-street1').val(),
      'addr-street2': $form.find('#addr-street2').val(),
      'addr-city': $form.find('#addr-city').val(),
      'addr-state': $form.find('#addr-state').val(),
      'addr-zip': $form.find('#addr-zip').val(),
    };

    const client = new ApiClient('v1');
    const uri = `users/${setting('dsUser.info.id')}/update`;
    client.post(uri, payload).then(callback);

    return false;
  });
}

/**
 * Initialize the Stripe donation form.
 * @param {jQuery} $donateForm - Donation form element
 */
function init($addressForm = $('#dosomething-address-form')) {
  if (!$addressForm.length) return;

  const $revealButton = $addressForm.find('[role=revealer]');
  const $submitForm = $addressForm.find('[role=submit]');

  const $form = $addressForm.find('form');

  $revealButton.on('click', () => $addressForm.toggleClass('js-reveal'));

  prefillForm($form);
  handleFormSubmit($form, (res) => {
    if (! res || ! res.data || ! res.data.id) {
      $addressForm.find('[role=error]').text('Looks like we had an error. Try again?');
      return;
    }

    $addressForm.toggleClass('js-reveal');
    $addressForm.find('[role=success]').text('Done!');
  });
}

export default { init };
