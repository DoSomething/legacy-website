import SlideshowController from './SlideshowController'

const React = require('react');

/**
 * Slideshow Component
 * <Slideshow />
 */
class Slideshow extends React.Component {
  constructor(props) {
    super(props);

    this.state = {
      activeSlide: 0
    };
  }

  moveSlide() {
    //
  }

  render() {
    return (
      <div className="slideshow">
        {this.props.slides[this.state.activeSlide]}

        <SlideshowController moveSlide={this.moveSlide}/>
      </div>
    );
  }
}

export default Slideshow;
