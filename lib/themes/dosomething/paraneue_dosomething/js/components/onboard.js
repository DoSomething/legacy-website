const React = require('react');
const ReactDOM = require('react-dom');

import Carousel from './carousel.js';

const Onboard = React.createClass({
  render: function() {
    return (
      <div className="onboard">
        <Carousel />
      </div>
    );
  }
});

if (localStorage.getItem('dosomething_enable_onboarding') == "true") {
  ReactDOM.render(
    <Onboard />,
    document.getElementById('onboarding')
  );
}
