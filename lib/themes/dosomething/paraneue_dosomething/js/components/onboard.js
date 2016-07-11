const React = require('react');

import Carousel from './carousel.js';

class Onboard extends React.Component {
  constructor(props) {
    super(props);
  }
  
  render() {
    return (
      <div className="onboard">
        <Carousel slides={this.props.slides} />
      </div>
    );
  }
}

export default Onboard;
