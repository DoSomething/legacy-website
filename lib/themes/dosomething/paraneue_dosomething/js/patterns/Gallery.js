import $ from 'jquery';
import debounce from 'lodash/debounce';
import Swapper from 'utilities/Swapper';
import Revealer from 'utilities/Revealer';

/**
 * Initialize galleries.
 */
function init($galleries = $('.gallery')) {
  const $mosaicGalleries = $galleries.filter('.-mosaic');
  const $revealGalleries = $galleries.filter('[data-show-more="true"]');

  // The Swapper swaps low resolution images for feature tiles in the "mosaic"
  // gallery pattern with higher resolution version from tablet size up.
  if ($mosaicGalleries.length && $mosaicGalleries.hasClass('-featured')) {
    const swappedImagesList = [];

    $(window).on('resize', debounce(function() {
      if (window.matchMedia('(min-width: 768px)').matches && !swappedImagesList.length) {
        $mosaicGalleries.each(function(index) {
          const $featureTile = $(this).find('li').first();
          swappedImagesList[index] = new Swapper($featureTile);
        });
      }
    }, 500));
  }

  // The Revealer is used to show or hide large galleries.
  if ($revealGalleries.length > 0) {
    const galleryList = [];

    $revealGalleries.each(function(index, gallery) {
      const $gallery = $(gallery);
      const $tiles = $gallery.find('> li');
      const isMosaicGallery = $gallery.hasClass('-mosaic');
      const initialItems = isMosaicGallery ? 5 : 6;
      const stepItems = isMosaicGallery ? 8 : 6;

      if ($tiles.length > initialItems) {
        galleryList[index] = new Revealer($gallery, $tiles, 'gallery', initialItems, stepItems);
      }
    });
  }
}

export default { init };
