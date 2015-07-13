import $ from 'jquery';
import debounce from 'lodash/function/debounce';
import Swapper from 'utils/Swapper';
import Revealer from 'utils/Revealer';

/**
 * Initialize galleries.
 */
function init($galleries = $('.gallery')) {
  // The Swapper swaps low resolution images for feature tiles in the "mosaic"
  // gallery pattern with higher resolution version from tablet size up.
  const $mosaicGalleries = $galleries.find('.-mosaic');
  if ($mosaicGalleries.length && $mosaicGalleries.hasClass('-featured')) {
    let swappedImagesList = [];

    $(window).on('resize', debounce(function () {
      if (window.matchMedia('(min-width: 768px)').matches && !swappedImagesList.length) {
        $mosaicGalleries.each(function (index) {
          var $featureTile = $(this).find('li').first();
          swappedImagesList[index] = new Swapper($featureTile);
        });
      }
    }, 500));

  }

  // The Revealer is used to show or hide large galleries.
  var $revealGalleries = $galleries.find('[data-show-more="true"]');

  if ($revealGalleries.length > 0) {
    var galleryList = [];

    $revealGalleries.each(function (index, gallery) {
      var $gallery = $(gallery);
      var $tiles = $gallery.find("li");
      var isMosaicGallery = $gallery.hasClass('-mosaic');
      var initialItems = isMosaicGallery ? 5 : 6;
      var stepItems = isMosaicGallery ? 8 : 6;

      if ($tiles.length > initialItems) {
        galleryList[index] = new Revealer($gallery, $tiles, "gallery", initialItems, stepItems);
      }
    });
  }
}

export default { init };
