const React = require('react');

/**
 * SlideshowController Component
 * <SlideshowController />
 */
class SlideshowController extends React.Component {
  render() {
    const disablePrevButton = this.props.currentSlide === 0;
    const disableNextButton = this.props.currentSlide === (this.props.totalSlides - 1);

    const dots = [];
    for (let i = 0; i < this.props.totalSlides; i++) {
      const activePage = this.props.currentSlide === i;
      dots.push(<li key={i} className={`slideshow__controller-indicator ${activePage ? '-active' : ''}`}>&bull;</li>);
    }

    return (
      <div className="slideshow__controller">
        <ul>
          {dots}
        </ul>

        <button className="button--prev" disabled={disablePrevButton} onClick={this.props.moveBackward}>Prev</button>
        <button className="button--next" disabled={disableNextButton} onClick={this.props.moveForward}>Next</button>
      </div>
    );
  }
}

export default SlideshowController;
