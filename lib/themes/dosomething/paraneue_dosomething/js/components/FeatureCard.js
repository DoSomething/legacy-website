const $ = require('jquery');
const React = require('react');

import Button from './Button';
import setting from '../utilities/Setting';
import ApiClient from '../utilities/ApiClient';
import { sortCampaignsByRelevance } from '../campaign/helpers';
import { sendEvent } from '../utilities/Analytics';

/**
 * Feature Card Component
 * <FeatureCard />
 */
class FeatureCard extends React.Component {
  constructor(props) {
    super(props);

    // These variables shouldn't force a state change & subsequent render
    this.requests = [];
    this.campaigns = [];
    this.campaignsToExclude = setting('dsUser.activity.signups', []);
    this.campaignsApiPage = 1;
    this.apiClient = new ApiClient('v1');

    this.state = {
      actionDisabled: false,
      campaignIndex: -1,
      isSignedUp: false,
      isLoading: false,
    };

    this.delay = null;
    this.signup = this.signup.bind(this);
  }

  componentDidMount() {
    this.getCampaigns(true, true, 1, () => {
      // Set the index so the first campaign renders
      this.setState({
        campaignIndex: 0
      });

      if (this.campaigns.length == 0) {
        // For our super users who already signed up for them all...
        this.viewAnother(false);
      }
      else {
        // These are all staff pick campaigns which we don't want to display twice.
        this.campaignsToExclude = this.campaignsToExclude.concat(this.campaigns.map(campaign => parseInt(campaign.id)));
      }
    });
  }

  getCampaigns(staffPickOnly, paginate, page, callback) {
    this.requests.push(this.serverRequest = $.get(`${this.apiClient.url}campaigns?${staffPickOnly ? 'staff_pick=true&' : ''}${page != -1 ? 'page=' + page : ''}`, result => {
      // Get campaigns ordered by relevance & handle exclusions.
      const campaigns = sortCampaignsByRelevance(result.data).filter(campaign => this.campaignsToExclude.indexOf(parseInt(campaign.id)) == -1);

      // Add it to the master list
      this.campaigns = this.campaigns.concat(campaigns);

      if (paginate) {
        // If we have pages left, paginate!
        if (result.pagination && result.pagination.total_pages > page) {
          this.getCampaigns(staffPickOnly, true, page + 1, callback);
        }
        else {
          callback();
        }
      }
      else {
        callback();
      }
    }));
  }

  componentWillUnmount() {
    this.requests.forEach(request => request.abort());
  }

  signup() {
    const campaign = this.campaigns[this.state.campaignIndex];

    if (!campaign) {
      return;
    }

    sendEvent('Onboarding', 'Signup'); // Soon to be removed.
    sendEvent('onboarding-v2', 'signup', this.constructor.name);

    this.campaignsToExclude.push(campaign.id);

    this.requests.push($.ajax({
      url: `${this.apiClient.url}campaigns/${campaign.id}/signup`,
      type: 'POST',
      headers: {
        "X-CSRF-Token": $('meta[name=csrf-token]').attr("content")
      },
      data: {
        source: 'onboarding'
      },
      success: (data) => {
        this.campaigns[this.state.campaignIndex].signedUp = true;
        this.setState({
          isLoading: false,
          isSignedUp: true
        });

        this.delay = setTimeout(() => {
          this.viewAnother(false);
        }, 3000);
      },
      beforeSend: () => {
        this.setState({
          actionDisabled: true,
          isLoading: true
        })
      }
    }));
  }

  getRemainingCampaigns() {
    return this.campaigns.length - this.state.campaignIndex;
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
      sendEvent('Onboarding', 'View More'); // Soon to be removed.
      sendEvent('onboarding-v2', 'view-more', this.constructor.name);
    }

    // If we're almost out of campaigns let's get more
    if (this.getRemainingCampaigns() <= 4) {
      this.getCampaigns(false, false, this.campaignsApiPage, () => {
        this.campaignsApiPage++;
        this.forceUpdate();
      });
    }

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

export default FeatureCard;
