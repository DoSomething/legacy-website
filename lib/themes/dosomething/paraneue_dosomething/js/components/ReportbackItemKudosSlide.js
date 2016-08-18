const React = require('react');

import ApiClient from '../utilities/ApiClient';
import ReportbackItem from './ReportbackItem';

/**
 * ReportbackItemKudosSlide Component
 * <ReportbackItemKudosSlide />
 */
class ReportbackItemKudosSlide extends React.Component {
  constructor(props) {
    super(props);

    this.state = {
      reportbackItems: null
    };

    this.apiClient = new ApiClient(window.location.hostname, '/api/v1/', window.location.port);
    this.reportbackItems = null;
  }

  componentDidMount() {
    const reportbackItems = this.apiClient.get('reportback-items', {
      'campaigns': this.props.campaign.id,
      'random': true,
      'count': 4,
      'status': 'promoted,approved'
    }, (response) => {
      this.setState({
        reportbackItems: response.data
      });
    });
  }

  renderReportbackItems(data, index) {
    return <li key={`list-item-${index}`}><ReportbackItem key={index} data={data} /></li>;
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
              <div className="container__block">
                <h2 className="heading -gamma">These members are rocking it already!</h2>
                <p>{/*Tap the heart to show them some love. */}We can't wait to see YOUR photos{user.info ? ', ' + user.info.first_name : ''}!</p>
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

export default ReportbackItemKudosSlide;
