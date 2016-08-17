const React = require('react');

import ApiClient from '../utilities/ApiClient';

/**
 * ReportbackItemKudosSlide Component
 * <ReportbackItemKudosSlide />
 */
class ReportbackItemKudosSlide extends React.Component {
  constructor(props) {
    super(props);

    this.apiClient = new ApiClient(window.location.hostname, '/api/v1/', window.location.port);
    this.reportbackItems = null;
  }

  componentDidMount() {
    const reportbackItems = this.apiClient.get('reportback-items', {
      'campaigns': '1283', // make dynamic
      'random': true,
      'count': 4
    }, (response) => {
      this.reportbackItems = response.data;
    });
  }

  render() {
    const user = this.props.user;

    console.log(this);

    return (
      <div className={`slideshow__slide ${this.props.isActive ? '-active fade-in': ''}`}>
        <div className="container">
          <div className="wrapper">

            <div className="container__row">
              <div className="container__block">
                <h2 className="heading -gamma">These members are rocking it already!</h2>
                <p>Tap the heart to show them some love. We can't wait to see YOUR photos{user.info ? ', ' + user.info.first_name : ''}!</p>
              </div>
            </div>

            <div className="container__row">
              <div className="container__block">
                <ul className="gallery -quartet">
                  <li>// items here</li>
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
