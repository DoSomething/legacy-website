const React = require('react');
const $ = require('jquery');

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

function sortCampaigns(a, b) {
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

    this.state = {
      campaigns: [],
      current_campaign: '',
      signup_animation: ''
    };
  }

  componentDidMount() {
    this.serverRequest = $.get(`${API_URL}campaigns?random=true&staff_pick=true`, result => {
      // Filter out campaigns users have signed up for & then sort remaining campaigns
      const userSignups = Drupal.settings.dsUser.activity.signups;
      const campaigns = result.data.filter(campaign => userSignups.indexOf(parseInt(campaign.id)) == -1).sort(sortCampaigns);

      this.setState({
        campaigns: campaigns,
        current_campaign_index: 0
      });
    });
  }

  componentWillUnmount() {
    if (this.serverRequest) {
      this.serverRequest.abort();;
    }
  }

  signup() {
    const campaign = this.state.campaigns[this.state.current_campaign_index];

    if (!campaign) {
      return;
    }

    $.ajax({
      url: `${API_URL}campaigns/${campaign.id}/signup`,
      type: 'POST',
      headers: {
        "X-CSRF-Token": $('meta[name=csrf-token]').attr("content")
      },
      data: {
        source: 'onboarding'
      },
      success: (data) => {
        setTimeout(() => {
          this.viewAnother();
        }, 1000);

        this.setState({ //TODO: Fancy animation
          signup_animation: 'tada'
        });
      }
    });
  }

  viewAnother() {
    let newIndex = this.state.current_campaign_index + 1;
    if (newIndex >= this.state.campaigns.length) {
      newIndex = 0;
    }

    this.setState({
      current_campaign_index: newIndex,
      signup_animation: ''
    });
  }

  render() {
    const campaign = this.state.campaigns[this.state.current_campaign_index];

    if (!campaign) {
      return null;
    }

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
              <img src={campaign.cover_image.default.sizes.square.uri} />
            </div>
          </div>

          <div className="beta-card__row">
            <div className="beta-card__block -centered">
              <h2 className="heading -delta">{campaign.title}</h2>
              <p className="tagline">{campaign.tagline}</p>
              <ul className="form-actions">
                <li><button className={`${this.state.signup_animation} button`} onClick={()=>this.signup()}>Sign Up</button></li>
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
