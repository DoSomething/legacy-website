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

  close() {
    this.setState({closed: true});

    // console.log(Drupal.settings.dsUser);
  }

  render() {
    if (this.state.closed === true) {
      return null;
    }

    return (
      <div id="onboarding" className="onboarding">
        <div className="wrapper">
          <Slideshow {...this.props} />

          <button className="onboarding__close-button" title="close" onClick={this.close}>&times;</button>
        </div>
      </div>
    );
  }
}

export default Onboarding;
