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

  realign() {
    window.scrollTo(0, 0);
  }

  getCurrentSlideName() {
    // Create a dummy component so we can grab the name.
    // TODO: This isn't the ideal way to do this, but this PR is contained to just data improvements.
    return React.createElement(this.props.slides[this.state.currentSlide], {key: 1, campaign: {}, user: {}, isActive: false}).type.name;
  }

  move(direction) {
    sendEvent('onboarding-v2', direction == 1 ? 'next' : 'prev' , this.getCurrentSlideName());

    this.setState({
      currentSlide: this.state.currentSlide + direction,
    });

    this.realign();
  }

  moveBackward() {
    sendEvent('Onboarding (Prev btn)', 'Slide Change', this.state.currentSlide - 1); // Soon to be removed.
    this.move(-1);
  }

  moveForward() {
    sendEvent('Onboarding (Next btn)', 'Slide Change', this.state.currentSlide + 1); // Soon to be removed.
    this.move(1);
  }

  componentDidMount() {
    sendEvent('onboarding-v2', 'started on', this.getCurrentSlideName());
  }

  componentWillUnmount() {
    sendEvent('Onboarding', 'Slideshow Closed', this.state.currentSlide); // Soon to be removed.
    sendEvent('onboarding-v2', 'closed' , this.getCurrentSlideName());
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
