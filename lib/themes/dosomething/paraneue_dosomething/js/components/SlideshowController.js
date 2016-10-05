import { sendEvent } from '../utilities/Analytics';

const React = require('react');

/**
 * SlideshowController Component
 * <SlideshowController />
 */
class SlideshowController extends React.Component {
  constructor(props) {
    super(props);

    this.finish = this.finish.bind(this);
  }

  finish() {
    sendEvent('onboarding-v2', 'finish' , this.props.currentSlideName);
    this.props.close();
  }

  getNextButton() {
    const showFinish = this.props.currentSlide === (this.props.totalSlides - 1);
    const click = showFinish ? this.finish : this.props.moveForward;
    const copy = showFinish ? "Finish" : "Next";

    return (
      <button className="button--next" onClick={click}>{copy}</button>
    );
  }

  render() {
    const disablePrevButton = this.props.currentSlide === 0;

    const dots = [];
    for (let i = 0; i < this.props.totalSlides; i++) {
      const activePage = this.props.currentSlide === i;
      dots.push(<li key={i} className={`slideshow__controller-indicator ${activePage ? '-active' : ''}`}>&bull;</li>);
    }

    const nextButton = this.getNextButton();

    return (
      <div className="slideshow__controller">
        <ul>
          {dots}
        </ul>

        <button className="button--prev" disabled={disablePrevButton} onClick={this.props.moveBackward}>Prev</button>
        {nextButton}
      </div>
    );
  }
}

export default SlideshowController;
