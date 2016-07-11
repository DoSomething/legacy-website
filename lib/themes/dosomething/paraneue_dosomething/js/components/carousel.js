const React = require('react');

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
        <div className="carousel__controls">
          buttons go here
        </div>
      </div>
    );
  }
}

export default Carousel;
