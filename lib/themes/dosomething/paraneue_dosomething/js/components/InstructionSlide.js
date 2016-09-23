const React = require('react');

const title = "Upload photos of yourself in action!";
const content = [
  "DoSomething.org staff reviews every single photo you send, and we’ll feature our favorites in the gallery on the site.",
  "We are PUMPED to see your photos. Complete these simple steps of yourself in action. Your pics will inspire others to join the movement -- upload photos and watch the likes roll in!"
];

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
      <div className={`slideshow__slide ${this.props.isActive ? '-active fade-in': ''}`}>
        <div className="container">
          <div className="wrapper">

            <div className="container__row">
              <div className="container__block -narrow -centered">
                <h2 className="heading -gamma">{title}</h2>
                {content.map(paragraph => {
                  return <p>{paragraph}</p>
                })}
              </div>
            </div>

            <div className="container__row">
              <div className="container__block -narrow -centered">
                <div className="media-video">
                  <video poster="https://static.dosomething.org/onboarding/poster.png" src="https://static.dosomething.org/onboarding/CouldBeYou_720p.mp4" loop autoPlay controls width="100%"></video>
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
