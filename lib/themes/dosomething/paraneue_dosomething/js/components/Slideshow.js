import SlideshowController from './SlideshowController'

const React = require('react');
const ReactDom = require('react-dom');

/**
 * Slideshow Component
 * <Slideshow />
 */
class Slideshow extends React.Component {
  constructor(props) {
    super(props);

    this.state = {
      activeSlide: 0
    };
  }

  moveSlide() {
    //
  }

  render() {
    const user = this.props.user;
    const campaign = this.props.campaign;

    const slides = this.props.slides.map((slide, index) => {
      return React.createElement(slide, {key: index, campaign: campaign, user: user});
    });

    return (
      <div className="slideshow">
        {slides}

        <SlideshowController moveSlide={this.moveSlide}/>
      </div>
    );
  }
}

export default Slideshow;
