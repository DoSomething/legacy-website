const $ = require('jquery');
const React = require('react');

import Button from './Button';
import setting from '../utilities/Setting';

const API_HOST = window.location.hostname;
const API_PORT = window.location.port || undefined;
const API_VERSION = '/api/v1/';
const API_URL = `//${API_HOST}${API_PORT ? ':' + API_PORT : ''}${API_VERSION}`;

function checkForSponsor(campaign) {
  const partners = campaign.affiliates.partners;
  if (partners.length < 1) {
    return false;
  }

  for (let partner of partners) {
    if (partner.sponsor) {
      return true;
    }
  }

  return false;
}

function rankCampaigns(a, b) {
  const aScore = a.time_commitment - (checkForSponsor(a) ? 1 : 0);
  const bScore = b.time_commitment - (checkForSponsor(b) ? 1 : 0);
  return aScore - bScore;
}

/**
 * Card Component
 * <Card />
 */
class FeatureCard extends React.Component {
  constructor(props) {
    super(props);

    // These variables shouldn't force a state change & subsequent render
    this.requests = [];
    this.campaigns = [];
    this.campaignsToExclude = setting('dsUser.activity.signups', []);
    this.campaignsApiPage = 1;

    this.state = {
      actionDisabled: false,
      campaignIndex: -1,
      isSignedUp: false,
      isLoading: false,
    };

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
    this.requests.push(this.serverRequest = $.get(`${API_URL}campaigns?${staffPickOnly ? 'staff_pick=true&' : ''}${page != -1 ? 'page=' + page : ''}`, result => {

      // Filter out campaigns users have signed up for & then rank remaining campaigns
      const campaigns = result.data.filter(campaign => this.campaignsToExclude.indexOf(parseInt(campaign.id)) == -1).sort(rankCampaigns);

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
    if (this.requests) {
      for (var request in this.requests) {
        request.abort();
      }
    }
  }

  signup() {
    const campaign = this.campaigns[this.state.campaignIndex];
    ga('send', 'event', 'Onboarding', 'Signup');

    if (!campaign) {
      return;
    }

    this.campaignsToExclude.push(campaign.id);

    this.requests.push($.ajax({
      url: `${API_URL}campaigns/${campaign.id}/signup`,
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

        setTimeout(() => {
          this.viewAnother(false);
        }, 5000);
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
    let newIndex = this.state.campaignIndex + 1;

    // Only log to GA if someone actually pressed the button
    if (buttonTrigger) {
      ga('send', 'event', 'Onboarding', 'View More');
    }

    // If we're almost out of campaigns let's get more
    if (this.getRemainingCampaigns() <= 4) {
      this.getCampaigns(false, false, this.campaignsApiPage, () => {
        this.campaignsApiPage++;
      });
    }

    // If we reached the end set our index back to the start
    if (newIndex >= this.campaigns.length) {
      newIndex = 0;
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
    const image_uri = campaign.cover_image.default != null ? campaign.cover_image.default.sizes.square.uri : '';

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
            <div className="beta-card__block">
              <img src={image_uri} />
            </div>
          </div>

          <div className="beta-card__row">
            <div className="beta-card__block -centered">
              <h2 className="heading -delta">{campaign.title}</h2>
              <p className="tagline">{campaign.tagline}</p>
              <ul className="form-actions">
                <li><Button classes={['-reactive']} loading={this.state.isLoading} disabled={this.state.actionDisabled} success={this.state.isSignedUp} onClick={this.signup}></Button></li>
                <li><a className="button -tertiary" onClick={()=>this.viewAnother(true)}>Show me another</a></li>
              </ul>
            </div>
          </div>
        </div>
      </article>
    )
  }
}

export default FeatureCard;
