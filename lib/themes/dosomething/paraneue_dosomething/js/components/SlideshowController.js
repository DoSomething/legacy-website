const React = require('react');

/**
 * SlideshowController Component
 * <SlideshowController />
 */
class SlideshowController extends React.Component {
  render() {
    return (
      <div className="slideshow__controller">
        <ul>
          <li>&bull;</li>
          <li>&bull;</li>
        </ul>

        <button className="button--prev" onClick={this.props.moveSlide}>Prev</button>
        <button className="button--next" onClick={this.props.moveSlide}>Next</button>
      </div>
    );
  }
}

export default SlideshowController;
