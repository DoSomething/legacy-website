const React = require('react');

import ContextSlide from './context_slide.js';

const Carousel = React.createClass({
  getInitialState: function() {
    return {
      activeSlide: 1,
    };
  },
  render: function() {
    var slide;
    switch (this.state.activeSlide) {
      case 1: slide = <ContextSlide />; break;
      case 2: // slide = Y
      case 3: // slide = Z
    }

    return (
      <div className="carousel">
        {slide}
        <div className="carousel__controls">
          buttons go here
        </div>
      </div>
    );
  }
});

export default Carousel;
