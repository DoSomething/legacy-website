import SlideshowController from './SlideshowController';
import { sendEvent } from '../utilities/Analytics';

const React = require('react');

/**
 * Slideshow Component
 * <Slideshow />
 */
class Slideshow extends React.Component {
  constructor(props) {
    super(props);

    this.state = {
      currentSlide: 0,
      animationDirection: 'left'
    };

    this.moveBackward = this.moveBackward.bind(this);
    this.moveForward = this.moveForward.bind(this);
  }

  moveBackward() {
    const slide = this.state.currentSlide - 1;
    sendEvent('Onboarding', 'Slide Change', slide);

    this.setState({
      currentSlide: slide,
    });
  }

  moveForward() {
    const slide = this.state.currentSlide + 1;
    sendEvent('Onboarding', 'Slide Change', slide);

    this.setState({
      currentSlide: slide,
    });
  }

  componentWillUnmount() {
    sendEvent('Onboarding', 'Slideshow Closed', this.state.currentSlide);
  }

  render() {
    const user = this.props.user;
    const campaign = this.props.campaign;

    const slides = this.props.slides.map((slide, index) => {
      const isActive = this.state.currentSlide == index;
      return React.createElement(slide, {key: index, campaign: campaign, user: user, isActive: isActive});
    });

    return (
      <div className="slideshow">
        {slides}

        <SlideshowController currentSlide={this.state.currentSlide} totalSlides={this.props.slides.length} moveBackward={this.moveBackward} moveForward={this.moveForward} />
      </div>
    );
  }
}

export default Slideshow;
