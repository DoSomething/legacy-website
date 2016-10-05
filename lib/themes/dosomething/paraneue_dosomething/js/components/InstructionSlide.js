import { sendEvent } from '../utilities/Analytics';

const React = require('react');

const title = "Upload photos of yourself in action!";
const content = [
  "DoSomething.org staff reviews every single photo you send, and we’ll feature our favorites in the gallery on the site.",
  "We are PUMPED to see your photos, so complete the simple steps below. Your pics will inspire others to join the movement -- upload photos and watch the likes roll in!"
];

/**
 * InstructionSlide Component
 * <InstructionSlide />
 */
class InstructionSlide extends React.Component {
  constructor(props) {
    super(props);

    this.setupListener = this.setupListener.bind(this);
    this.playVideo = this.playVideo.bind(this);
    this.video = null;
  }

  playVideo() {
    if (!this.video) {
      return;
    }

    if (this.props.isActive) {
      this.video.play();
    }
    else {
      this.video.pause();
    }
  }

  setupListener(video) {
    if (!video) {
      return;
    }

    video.addEventListener('ended', this.handleVideoFinish.bind(this), false);
    this.video = video;
    this.playVideo();
  }

  handleVideoFinish(video) {
    if (this.props.isActive) {
      sendEvent('onboarding-v2', 'video-finish', InstructionSlide.analyticsIdentifier);
      this.playVideo();
    }
  }

  componentDidUpdate() {
    this.playVideo();
  }

  render() {
    return (
      <div className={`slideshow__slide ${this.props.isActive ? '-active fade-in': ''}`}>
        <div className="container -compact">
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
                  <video ref={this.setupListener} poster="https://static.dosomething.org/onboarding/poster.png" src="https://static.dosomething.org/onboarding/CouldBeYou_720p.mp4" controls width="100%"></video>
                </div>
              </div>
            </div>

          </div>
        </div>
      </div>
    );
  }
}

InstructionSlide.analyticsIdentifier = 'Slide - Instructions';

export default InstructionSlide;
