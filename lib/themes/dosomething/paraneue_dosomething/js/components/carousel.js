const React = require('react');

/**
 * Carousel Component
 * <Carousel />
 */
class Carousel extends React.Component {
  constructor(props) {
    super(props);

    this.state = {
      activeSlide: 0
    };
  }

  render() {
    return (
      <div className="carousel">
        {this.props.slides[this.state.activeSlide]}

        <ul className="carousel__controls">
          <li><a href="#">Prev</a></li>
          <li><a href="#">Next</a></li>
        </ul>
      </div>
    );
  }
}

export default Carousel;
