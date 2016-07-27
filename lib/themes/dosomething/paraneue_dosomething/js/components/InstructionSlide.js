const React = require('react');

const title = "This is how you do it.";
const body = "We are PUMPED to see your photos. Complete these simple steps and upload a photo of yourself in action. Your pics will inspire others to join the movement &ndash; so don't forget to share them!";

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
                <h2 className="heading -gamma">{title}</h2>
                <p>{body}</p>
              </div>
            </div>

            <div className="container__row">
              <div className="container__block -narrow -centered">
                <div className="beta-card">
                  <video className="beta-card__video" poster="https://static.dosomething.org/onboarding/poster.png" src="https://static.dosomething.org/onboarding/CouldBeYou_720p.mp4" loop autoPlay controls width="100%"></video>
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
