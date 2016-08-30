import Layzr from 'layzr.js';

// Application lazy loader instance.
let loader = null;

/**
 * Helper function to check for new [data-src] elements that were added
 * after DOMContentLoaded and lazy-load them.
 */
export function update() {
  if (loader === null) {
    throw new Error('Lazy loader has not been initialized.');
  }

  loader.update().check();
}

/**
 * Initialize a new lazy loader.
 *
 * @returns Layzr
 */
export function init() {
  if (loader !== null) {
    return loader;
  }

  loader = new Layzr({
    normal: 'data-src',
    retina: 'data-src-retina',
  });

  loader.on('src:before', image => {
    // On load, set the images to be transparent so we can fade them in.
    image.style.transition = 'opacity 0.5s ease-in';
    image.style.opacity = 0;

    // And when the load event fires, set opacity to full.
    image.addEventListener('load', event => event.target.style.opacity = 1);
  });

  loader
    .update() // Find [data-src] elements in the DOM.
    .check() // Check if they're in the viewport on load.
    .handlers(true);  // Bind scroll and resize handlers.

  return loader;
}

export default { init };
