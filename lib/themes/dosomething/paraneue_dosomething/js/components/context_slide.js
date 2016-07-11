const React = require('react');

const ContextSlide = React.createClass({
  render: function() {
    return (
      <div className="carousel__slide">
        <h1>{"Woohoo! You're signed up."}</h1>
        <p>here is some text</p>
      </div>
    )
  }
});

export default ContextSlide;
