const React = require('react');

const Carousel = React.createClass({
  getInitialState: function() {
    return {
      activeSlide: 0,
    };
  },
  render: function() {
    return (
      <div className="carousel">
        {this.props.slides[this.state.activeSlide]}
        <div className="carousel__controls">
          buttons go here
        </div>
      </div>
    );
  }
});

export default Carousel;
