const React = require('react');

import ApiClient from '../utilities/ApiClient';
import ReportbackItem from './ReportbackItem';

const title = "Welcome to our global movement for good!";
const content = [
  "By signing up for the [CAMPAIGN NAME] campaign, you’ve teamed up with 5.3 million other DoSomething.org members who are making positive change right now.",
  "These members (and thousands of others!) are already taking action on [CAMPAIGN NAME], so tap the heart to show them some love. Then get started! Do the campaign, take photos of yourself in action, and upload them to the site. LET’S DO THIS."
];

/**
 * ReportbackItemsSlide Component
 * <ReportbackItemsSlide />
 */
class ReportbackItemsSlide extends React.Component {
  constructor(props) {
    super(props);

    this.state = {
      reportbackItems: null
    };

    this.apiClient = new ApiClient('v1');
    this.reportbackItems = null;

    this.renderReportbackItems = this.renderReportbackItems.bind(this);

    const competition = Drupal.settings.dosomethingSignup ? Drupal.settings.dosomethingSignup.competition : null;
    if (competition && competition.joined && competition.messages) {
      content.push(competition.messages.confirmation);
    }
  }

  componentDidMount() {
    this.apiClient.get('reportback-items', {
      campaigns: this.props.campaign.id,
      random: true,
      count: 4,
      status: 'promoted,approved'
    }).then(response => {
      this.setState({
        reportbackItems: response.data
      });
    });
  }

  renderReportbackItems(data, index) {
    return <li key={`list-item-${index}`}><ReportbackItem key={index} data={data} user={this.props.user} /></li>;
  }

  render() {
    const user = this.props.user;

    let listContent = 'Waiting for content...';

    if (!this.state.reportbackItems) {
      // @TODO: Add loading spinnner??
    }

    if (this.state.reportbackItems) {
      listContent = this.state.reportbackItems.map(this.renderReportbackItems);
    }

    return (
      <div className={`slideshow__slide ${this.props.isActive ? '-active fade-in': ''}`}>
        <div className="container">
          <div className="wrapper">

            <div className="container__row">
              <div className="container__block -narrow">
                <h2 className="heading -gamma">{title}</h2>
                {content.map(paragraph => {
                  return <p>{paragraph.replace('[CAMPAIGN NAME]', this.props.campaign.title)}</p>
                })}
              </div>
            </div>

            <div className="container__row">
              <div className="container__block">
                <ul className="gallery -quartet">
                  {listContent}
                </ul>
              </div>
            </div>

          </div>
        </div>
      </div>
    );
  }
}

ReportbackItemsSlide.analyticsIdentifier = 'Slide - Reportbacks';

export default ReportbackItemsSlide;
