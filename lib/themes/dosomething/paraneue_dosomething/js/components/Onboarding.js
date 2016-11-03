import Slideshow from './Slideshow';

const React = require('react');

/**
 * Onboarding Component
 * <Onboarding />
 */
class Onboarding extends React.Component {
  constructor(props) {
    super(props);

    this.state = {
      closed: false,
    };

    // Bind `this` to event handlers.
    this.close = this.close.bind(this);
  }

  realign() {
    window.scrollTo(0, 0);
  }

  close() {
    this.realign();
    this.setState({closed: true});
  }

  render() {
    if (this.state.closed === true) {
      return null;
    }

    return (
      <div id="onboarding" className="onboarding">
        <div className="wrapper">
          <Slideshow {...this.props} close={this.close} realign={this.realign} />

          <button className="onboarding__close-button" title="close" onClick={this.close}>&times;</button>
        </div>
      </div>
    );
  }
}

export default Onboarding;
