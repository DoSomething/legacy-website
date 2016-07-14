import SlideshowController from './SlideshowController'

const React = require('react');

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

    return (
      <div className="slideshow">
        {React.createElement(this.props.slides[this.state.activeSlide], {campaign: campaign, user: user})}

        <SlideshowController moveSlide={this.moveSlide}/>
      </div>
    );
  }
}

export default Slideshow;
