import SlideshowController from './SlideshowController';

const React = require('react');
const ReactCSSTransitionGroup = require('react-addons-css-transition-group');

/**
 * Slideshow Component
 * <Slideshow />
 */
class Slideshow extends React.Component {
  constructor(props) {
    super(props);

    this.state = {
      currentSlide: 0,
      totalSlides: this.props.slides.length
    };

    this.moveBackward = this.moveBackward.bind(this);
    this.moveForward = this.moveForward.bind(this);
  }

  moveBackward() {
    const slide = this.state.currentSlide - 1;

    this.setState({
      currentSlide: slide
    });
  }

  moveForward() {
    const slide = this.state.currentSlide + 1;

    this.setState({
      currentSlide: slide
    });
  }

  render() {
    const user = this.props.user;
    const campaign = this.props.campaign;

    const slides = this.props.slides.map((slide, index) => {
      return React.createElement(slide, {key: index, campaign: campaign, user: user});
    });

    return (
      <div className="slideshow">
        <ReactCSSTransitionGroup className="slideshow__carousel" transitionName="slide" component="div" transitionEnterTimeout={10000} transitionLeaveTimeout={10000}>
          {slides[this.state.currentSlide]}
        </ReactCSSTransitionGroup>

        <SlideshowController currentSlide={this.state.currentSlide} totalSlides={this.state.totalSlides} moveBackward={this.moveBackward} moveForward={this.moveForward} />
      </div>
    );
  }
}

export default Slideshow;
