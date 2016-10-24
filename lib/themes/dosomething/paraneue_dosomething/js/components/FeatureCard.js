const $ = require('jquery');
const React = require('react');

import Button from './Button';
import { sendEvent } from '../utilities/Analytics';
import CampaignController from '../campaign/CampaignController';

/**
 * Feature Card Component
 * <FeatureCard />
 */
class FeatureCard extends React.Component {
  constructor(props) {
    super(props);

    this.state = {
      actionDisabled: false,
      campaignIndex: -1,
      isSignedUp: false,
      isLoading: false,
    };

    this.campaigns = [];
    this.controller = new CampaignController();
    this.delay = null;
    this.signup = this.signup.bind(this);
  }

  componentDidMount() {
    // Grab initial batch of campaigns.
    this.getCampaigns(true, 1, () => {
      // Set the index so the first campaign renders
      this.setState({
        campaignIndex: 0
      });
    });
  }

  getCampaigns(staffPick, page, onRecieve) {
    this.controller.getCampaigns({
      isStaffPick: staffPick,
      page: page,
      removeDuplicateResults: true,
      sortByRelevance: true,
      removeSignups: true
    }).then(campaigns => {
      this.campaigns = this.campaigns.concat(campaigns);

      // For our super duper users the campaigns array might be empty.
      this.getRemainingCampaigns();
    }).then(onRecieve);
  }

  signup() {
    const campaign = this.campaigns[this.state.campaignIndex];

    if (!campaign) {
      return;
    }

    sendEvent('onboarding-v2', 'signup', FeatureCard.analyticsIdentifier);

    this.setState({
      actionDisabled: true,
      isLoading: true
    });

    this.controller.signup(campaign.id, 'onboarding').then(() => {
      this.campaigns[this.state.campaignIndex].signedUp = true;
      this.setState({
        isLoading: false,
        isSignedUp: true
      });

      this.delay = setTimeout(() => {
        this.viewAnother(false);
      }, 3000);
    });
  }

  getRemainingCampaigns() {
    if ((this.campaigns.length - this.state.campaignIndex) <= 4) {
      this.controller.campaignsApiPage++;
      this.getCampaigns(false, this.controller.campaignsApiPage, () => {
        this.forceUpdate();
      });
    }
  }

  viewAnother(buttonTrigger) {
    clearTimeout(this.delay);

    let newIndex = this.state.campaignIndex + 1;

    // If we reached the end set our index back to the start
    if (newIndex >= this.campaigns.length) {
      newIndex = 0;
    }

    // Only log to GA if someone actually pressed the button
    if (buttonTrigger) {
      sendEvent('onboarding-v2', 'view-more', this.constructor.name);
    }

    // If we're almost out of campaigns let's get more
    this.getRemainingCampaigns();

    // Re-render with new index
    this.setState({
      actionDisabled: false,
      campaignIndex: newIndex,
      isSignedUp: false
    });
  }

  render() {
    const campaign = this.campaigns[this.state.campaignIndex];

    if (!campaign) {
      return null;
    }

    // Fix for local files / data missing by preventing null error
    const image_uri = campaign.cover_image.default != null ? campaign.cover_image.default.sizes.landscape.uri : '';

    return (
      <article className="beta-card">
        <header className="beta-card__header">
          <div className="beta-card__row">
            <div className="beta-card__block">
              <h1 className="heading -beta -emphasized">{this.props.content.title}</h1>
            </div>
          </div>
        </header>

        <div className="beta-card__body">
          <div className="beta-card__row">
            <img src={image_uri} />
          </div>

          <div className="beta-card__row">
            <div className="beta-card__block -centered">
              <h2 className="heading -delta">{campaign.title}</h2>
              <p className="tagline">{campaign.tagline}</p>
              <ul className="form-actions">
                <li><Button reactive={true} loading={this.state.isLoading} disabled={this.state.actionDisabled} success={this.state.isSignedUp} onClick={this.signup}>Sign Up</Button></li>
                <li><Button type="tertiary" onClick={()=>this.viewAnother(true)}>Show me another</Button></li>
              </ul>
            </div>
          </div>
        </div>
      </article>
    )
  }
}

FeatureCard.analyticsIdentifier = 'Card - Campaign Feature';

export default FeatureCard;
