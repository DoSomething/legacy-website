import CampaignController from '../campaign/Controller';
import SignupCard from './SignupCard';

const React = require('react');

/**
 * CampaignSlide Component
 * <CampaignSlide />
 */
class CampaignSlide extends React.Component {
  constructor(props) {
    super(props);

    this.controller = new CampaignController();
  }

  componentDidMount() {
    // get campaigns, this.controller.getCampaigns({
  }

  render() {
    return (
      <div className={`slideshow__slide ${this.props.isActive ? '-active fade-in': ''}`}>
        <div className="container">
          <div className="wrapper">

            <div className="container__block">
              <h2 className="heading -gamma">Woohoo! You're signed up.</h2>
              <p>As a DoSomething.org member, you're part of something bigger. You're part of a global movement for good.</p>

              <p>You'll get all the tools you need to create impact. You've already joined {this.props.campaign.title}. Now sign up for other popular campaigns!</p>
            </div>

            <SignupCard image_uri="" tagline="Test tagline here" title="Test title" />

          </div>
        </div>
      </div>
    )
  }
}

export default CampaignSlide;
