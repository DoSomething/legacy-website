import { sendEvent } from '../utilities/Analytics';

const React = require('react');

const title = "This is how you do it.";
const body = "We are PUMPED to see your photos. Complete these simple steps and upload a photo of yourself in action. Your pics will inspire others to join the movement \u2013 so don't forget to share them!";

/**
 * InstructionSlide Component
 * <InstructionSlide />
 */
class InstructionSlide extends React.Component {
  constructor(props) {
    super(props);
  }

  componentDidMount() {
    document.getElementById('onboarding-video').addEventListener('canplaythrough', this.handleVideoFinish.bind(this), false);
  }

  handleVideoFinish() {
    if (this.props.isActive) {
      sendEvent('onboarding-v2', 'video-finish', this.constructor.name);
    }
  }

  render() {
    return (
      <div className={`slideshow__slide ${this.props.isActive ? '-active fade-in': ''}`}>
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
                <div className="media-video">
                  <video id="onboarding-video" poster="https://static.dosomething.org/onboarding/poster.png" src="https://static.dosomething.org/onboarding/CouldBeYou_720p.mp4" loop  autoPlay={this.props.isActive ? 'true' : 'false'} controls width="100%"></video>
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
