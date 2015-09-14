import $ from 'jquery';

class Revealer {
  /**
   * Allows for specified grouping of elements to be hidden and then revealed
   * via an interactive "Show More" button.
   *
   * @param {jQuery} $container The container element object that encloses the items to hide.
   * @param {jQuery} $content   A collection of objects to hide.
   * @param {string} category   Specify a category type for the content to provide more unique behavior.
   * @param {int} initialItems  Amount of items to initially display.
   * @param {int} stepItems     Amount of items to step by
   */
  constructor($container, $content, category, initialItems, stepItems) {
    this.$container = $container;
    this.$content = $content;
    this.$button = $(`<button class=\"button -tertiary\">${Drupal.t('Show More')}</button>`);
    this.category = category;
    this.initialItems = initialItems;
    this.stepItems = stepItems;
    this.steps = {
      // Array of step items to include with each button interaction.
      items: [],

      // Number of steps.
      count: 0,
    };

    this.init();
  }

  init() {
    if (this.category === 'gallery') {
      this.prepGalleryItems();
    } else {
      this.steps.items.push(this.$content);
    }

    this.steps.count = this.steps.items.length;

    this.detachContent();
    this.enableButton();
  }

  detachContent() {
    this.$content.detach();
  }

  reattachContent(content) {
    this.$container.append(content);
  }

  enableButton() {
    const _this = this;

    this.$button.insertAfter(this.$container);

    this.$button.on('click', function() {
      if (_this.steps.count > 0) {
        _this.reattachContent(_this.steps.items.shift());
        _this.steps.count--;
      }

      if (_this.steps.count === 0) {
        _this.$button.remove();
      }
    });
  }

  prepGalleryItems() {
    const content = this.$content.slice(this.initialItems);
    let collection = $.makeArray(content);

    this.$content = content;

    // Multiple step reveals.
    if (this.$content.length > this.stepItems) {
      while (collection.length > 0) {
        this.steps.items.push(collection.splice(0, this.stepItems));
      }
    } else {
      this.steps.items.push(collection);
    }

    collection = null;
  }
}

export default Revealer;
