const React = require('react');

/**
 * SlideshowController Component
 * <SlideshowController />
 */
class SlideshowController extends React.Component {
  render() {
    const disablePrevButton = this.props.currentSlide === 0 ? true : false;
    const disableNextButton = this.props.currentSlide === (this.props.totalSlides - 1) ? true : false;

    return (
      <div className="slideshow__controller">
        <ul>
          <li>&bull;</li>
          <li>&bull;</li>
        </ul>

        <button className="button--prev" disabled={disablePrevButton} onClick={this.props.moveBackward}>Prev</button>
        <button className="button--next" disabled={disableNextButton} onClick={this.props.moveForward}>Next</button>
      </div>
    );
  }
}

export default SlideshowController;
