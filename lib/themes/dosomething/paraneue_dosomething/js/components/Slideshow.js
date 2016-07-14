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

    this.renderSlide = this.renderSlide.bind(this);
  }

  moveSlide() {
    //
  }

  renderSlide(slide) {
    console.log('a slide');
  }

  render() {
    const user = this.props.user;
    const campaign = this.props.campaign;

    return (
      <div className="slideshow">
        {/* Why does this.renderSlide not work? */}
        {this.props.slides.map(function (slide, index) {
          return React.createElement(slide, {key: index, campaign: campaign, user: user});
        })}

        <SlideshowController moveSlide={this.moveSlide}/>
      </div>
    );
  }
}

export default Slideshow;
