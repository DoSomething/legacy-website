class Swapper {

  constructor($content) {
    const $image = $content.find('img');
    const srcLarge = $image.data('src-large') || null;

    this.$image = $image;

    this.exchange(srcLarge);
  }

  exchange(url) {
    if (url) {
      this.$image.attr('src', url);
    }
  }

}

export default Swapper;
