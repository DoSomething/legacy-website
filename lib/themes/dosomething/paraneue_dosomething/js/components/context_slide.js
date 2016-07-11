const React = require('react');

class ContextSlide extends React.Component {
  constructor(props) {
    super(props);
  }
  
  render() {
    return (
      <div className="carousel__slide">
        <h1>{"Woohoo! You're signed up."}</h1>
        <p>here is some text</p>
      </div>
    );
  }
}

export default ContextSlide;
