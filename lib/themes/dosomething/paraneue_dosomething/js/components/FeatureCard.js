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
  // const aScore = a.time_commitment - (checkForSponsor(a) ? 1 : 0) + (a.staff_pick ? 2 : 0);
  // const bScore = b.time_commitment - (checkForSponsor(b) ? 1 : 0) + (a.staff_pick ? 2 : 0);
  // return aScore - bScore;

  // something like
  // if only one is a sponsor
  // return 1 or -1
  // else if one is a corporate
  // return 1 or -1
  // else
  // return based on least time commit

  return 0;
}

/**
 * Card Component
 * <Card />
 */
class FeatureCard extends React.Component {
  constructor(props) {
    super(props);

    this.requests = [];
    this.state = {
      signupAnimation: '',
      campaignPage: 1,
      campaigns: []
    };
  }

  componentDidMount() {
    // First load staff pick campaigns to quickly initialize the card
    this.getCampaigns(1, campaigns => {
      this.setState({
        campaigns: campaigns
      });

      // For our crazy super users, double check they actually have campaigns to see!
      this.checkCampaignsRemaining();
    });
  }

  componentWillUnmount() {
    if (this.requests) {
      for (var request in this.requests) {
        request.abort();
      }
    }
  }

  checkCampaignsRemaining() {
    // If we're almost out of campaigns let's get more
    if (this.state.campaigns.length < 4) {
      // First update the API page
      this.setState({campaignPage: this.state.campaignPage + 1});
      // Then grab campaigns for that page & update the state
      this.getCampaigns(this.state.campaignPage, campaigns => {
        // this.setState({
        //   campaigns: campaigns
        // })
      });
    }
  }

  getCampaigns(page, cb) {
    // Grab all campaigns for given page
    // The staff_pick=true is embedded within the template string intentionally,
    // it seems like the precense alone of the param causes it to execute..
    this.requests.push($.get(`${API_URL}campaigns?page=${page}`, result => {
      let rawCampaigns = result.data;console.log(result);

      // Filter out campaigns users have signed up for
      const userSignups = Drupal.settings.dsUser.activity.signups;
      rawCampaigns = rawCampaigns.filter(campaign => userSignups.indexOf(parseInt(campaign.id)) == -1);

      // Finally sort by weight values
      rawCampaigns = rawCampaigns.sort(sortCampaigns)

      // Join previous campaigns with newly retrieved
      const campaigns = this.state.campaigns.concat(rawCampaigns);

      cb(campaigns);
    }));
  }

  signup(campaign) {
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
        setTimeout(() => {
          this.viewAnother();
        }, 1000);

        this.setState({ //TODO: Fancy animation
          signupAnimation: 'tada'
        });
      }
    }));
  }

  viewAnother() {
    // Remove current campaign
    this.state.campaigns.splice(0, 1);

    // Remove temp animation class
    this.setState({
      signupAnimation: '',
    });

    // Make sure we didn't run out of campaigns!
    this.checkCampaignsRemaining();
  }

  render() {
    const campaign = this.state.campaigns[0];

    if (!campaign) {
      return null;
    }

    // Local campaign files are sometimes borked, quick fix (DS Logo)
    if (campaign.cover_image.default == undefined) {
      campaign.cover_image.default = {sizes: {square: {uri: ''}}};
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
                <li><button className={`${this.state.signupAnimation} button`} onClick={()=>this.signup()}>Sign Up</button></li>
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
