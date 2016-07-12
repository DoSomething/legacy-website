import Carousel from './Carousel.js';

const React = require('react');

/**
 * Onboarding Component
 * <Onboarding />
 */
class Onboarding extends React.Component {
  constructor(props) {
    super(props);
  }

  render() {
    return (
      <Carousel slides={this.props.slides} />
    );
  }
}

export default Onboarding;
