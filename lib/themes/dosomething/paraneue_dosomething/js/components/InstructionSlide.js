const React = require('react');

/**
 * InstructionSlide Component
 * <InstructionSlide />
 */
class InstructionSlide extends React.Component {
  constructor(props) {
    super(props);
  }

  render() {
    return (
      <div className="slideshow__slide">
        <div className="container">
          <div className="wrapper">

            <div className="container__row">
              <div className="container__block -narrow -centered">
                <h2 className="heading -gamma">This is how you do it.</h2>
                <p>We are PUMPED to see your photos. Complete these simple steps and upload a photo of yourself in action. Your pics will inspire others to join the movement &ndash; so don't forget to share them!</p>
              </div>
            </div>

            <div className="container__row">
              <div className="container__block -narrow -centered">
                <div className="beta-card">
                  <img src="http://placekitten.com/1080/330" alt=""/>
                </div>
              </div>
            </div>

          </div>
        </div>
      </div>
    );
  }
}

export default InstructionSlide;
