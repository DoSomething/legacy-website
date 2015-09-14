import $ from 'jquery';

const width = 550;
const height = 420;
const winHeight = screen.height;
const winWidth = screen.width;

/**
 * Open given link in a popup dialog.
 * @param {string} href - Share dialog URL
 */
function popup(href) {
  // Open share links in a popup dialog.
  const left = Math.round((winWidth / 2) - (width / 2));
  let top = 0;

  if (winHeight > height) {
    top = Math.round((winHeight / 2) - (height / 2));
  }

  window.open(href, 'intent', `scrollbars=yes,resizable=yes,toolbar=no,
      location=yes,width=${width},height=${height},left=${left},top=${top}`);
}

function init() {
  $('body').on('click', 'a.js-share-link', function(event) {
    event.preventDefault();
    popup(this.href);
  });
}

export default { init, popup };
