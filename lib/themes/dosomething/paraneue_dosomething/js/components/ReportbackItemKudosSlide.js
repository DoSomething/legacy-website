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
  }

  componentDidMount() {
    // retrieve the RB Items via API
  }

  render() {
    const user = this.props.user;

    return (
      <div className="slideshow__slide">
        <div className="container">
          <div className="wrapper">

            <div className="container__row">
              <div className="container__block">
                <h2 className="heading -gamma">These members are rocking it already!</h2>
                <p>Tap the heart to show them some love. We can't wait to see YOUR photos{user.info ? ', ' + user.info.first_name : ''}!</p>
              </div>
            </div>

            {/*
            <div className="container__row">
              <div className="container__block">
                 <!-- @TODO: Include Reportback Items for Kudos-ing here! -->
              </div>
            </div>
            */}

          </div>
        </div>
      </div>
    );
  }
}

export default ReportbackItemKudosSlide;
