const React = require('react');

import Carousel from './carousel.js';

const Onboard = React.createClass({
  render: function() {
    return (
      <div className="onboard">
        <Carousel slides={this.props.slides} />
      </div>
    );
  }
});

export default Onboard;
