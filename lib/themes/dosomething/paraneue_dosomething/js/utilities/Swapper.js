
class Swapper {

  constructor($content) {
    this.$image   = $content.find("img");

    var srcLarge = this.$image.data("src-large") || null;

    this.exchange(srcLarge);
  }

  /**
   *
   * @param url
   */
  exchange(url) {
    if (url) {
      this.$image.attr("src", url);
    }
  }

}


export { Swapper };
