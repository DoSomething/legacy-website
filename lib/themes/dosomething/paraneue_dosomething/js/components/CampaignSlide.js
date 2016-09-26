import CampaignController from '../campaign/Controller';
import CampaignSignupCard from './CampaignSignupCard';

const React = require('react');

const title = "Join these HOT campaigns, trending now.";
const body = "You’ve already signed up for [CAMPAIGN NAME], which is awesome! Here are three other campaigns that thousands of other members are doing right now. Get in on the action while it’s hot!";

/**
 * CampaignSlide Component
 * <CampaignSlide />
 */
class CampaignSlide extends React.Component {
  constructor(props) {
    super(props);

    this.state = {
      campaigns: []
    };

    this.controller = new CampaignController();
    this.renderHeader = this.renderHeader.bind(this);
  }

  componentDidMount() {
    const args = {
      'isStaffPick': true,
      'removeDuplicateResults': true,
      'sortByRelevance': true,
      'removeSignups': true
    };

    this.controller.getCampaigns(args).then(campaigns => {
      this.setState({
        campaigns: campaigns.splice(0, 3) // Grab the first 3 campaigns returned
      });

      // For our crazy super users, remove staff pick filter & fill remaining spots
      const missingCampaigns = 3 - this.state.campaigns.length;
      if (missingCampaigns > 0) {
        args['isStaffPick'] = false;

        this.controller.getCampaigns(args).then(campaigns => {
          this.setState({
            campaigns: this.state.campaigns.concat(campaigns.splice(0, missingCampaigns))
          });
        });
      }
    });
  }

  render() {
    return (
      <div className={`slideshow__slide ${this.props.isActive ? '-active fade-in': ''}`}>
        <div className="container">
          <div className="wrapper">
            {this.renderHeader()}

            <div className="gallery -triad">
              {this.state.campaigns.map(campaign => {
                // Fix for local files / data missing by preventing null error
                const image_uri = campaign.cover_image.default != null ? campaign.cover_image.default.sizes.landscape.uri : '';
                return (
                  <li key={campaign.id}>
                    <CampaignSignupCard image_uri={image_uri} tagline={campaign.tagline}
                      title={campaign.title} signup={this.controller.signup} id={campaign.id} />
                  </li>
                );
              })}
            </div>
          </div>
        </div>
      </div>
    )
  }

  renderHeader() {
    return (
      <div className="container__block">
        <h2 className="heading -gamma">{title}</h2>
        <p>{body.replace('[CAMPAIGN NAME]', this.props.campaign.title)}</p>
      </div>
    );
  }
}

export default CampaignSlide;
