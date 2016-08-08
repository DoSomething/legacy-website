const React = require('react');
const $ = require('jquery');

import setting from '../utilities/Setting';

const API_HOST = window.location.hostname;
const API_PORT = window.location.port || undefined;
const API_VERSION = '/api/v1/';
const API_URL = `http://${API_HOST}${API_PORT ? ':' + API_PORT : ''}${API_VERSION}`;

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
      campaignIndex: -1,
      isSignedUp: ''
    };
  }

  componentDidMount() {
    this.getCampaigns(true, true, 1, () => {
      // Set the index so the first campaign renders
      this.setState({
        campaignIndex: 0
      });

      if (this.campaigns.length == 0) {
        // For our super users who already signed up for them all...
        this.viewAnother();
      }
      else {
        // These are all staff pick campaigns which we don't want to display twice.
        this.campaignsToExclude.concat(this.campaigns.map(campaign => parseInt(campaign.id)));
      }
    });
  }

  getCampaigns(staffPickOnly, paginate, page, cb) {
    this.requests.push(this.serverRequest = $.get(`${API_URL}campaigns?${staffPickOnly ? 'staff_pick=true&' : ''}${page != -1 ? 'page=' + page : ''}`, result => {

      // Filter out campaigns users have signed up for & then rank remaining campaigns
      const campaigns = result.data.filter(campaign => this.campaignsToExclude.indexOf(parseInt(campaign.id)) == -1).sort(rankCampaigns);

      // Add it to the master list
      this.campaigns = this.campaigns.concat(campaigns);

      if (paginate) {
        // If we have pages left, paginate!
        if (result.pagination && result.pagination.total_pages > page) {
          this.getCampaigns(staffPickOnly, true, page + 1, cb);
        }
        else {
          cb();
        }
      }
      else {
        cb();
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
        this.setState({ //TODO: Fancy animation
          isSignedUp: true
        });

        setTimeout(() => {
          this.viewAnother();
        }, 1000);
      }
    }));
  }

  getRemainingCampaigns() {
    return this.campaigns.length - this.state.campaignIndex;
  }

  viewAnother() {
    let newIndex = this.state.campaignIndex + 1;

    // If we're almost out of campaigns let's get more
    if (this.getRemainingCampaigns() <= 4) {
      this.getCampaigns(false, false, this.campaignsApiPage, () => {
        this.campaignsApiPage++;
      });
    }

    // If we reeached the end set our index back to the start
    if (newIndex >= this.campaigns.length) {
      newIndex = 0;
    }

    // Re-render with new index
    this.setState({
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
                {(campaign.signedUp && !this.state.isSignedUp) ? <h1>You're signed up already!</h1> : <li><button className={`${this.state.isSignedUp ? 'tada' : ''} button`} onClick={()=>this.signup()}>Sign Up</button></li>}
                <li><a className="button -tertiary" onClick={()=>this.viewAnother()}>Show me another</a></li>
              </ul>
            </div>
          </div>
        </div>
      </article>
    )
  }
}

export default FeatureCard;
