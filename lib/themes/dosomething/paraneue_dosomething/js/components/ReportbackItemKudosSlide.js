const React = require('react');

/**
 * ReportbackItemKudosSlide Component
 * <ReportbackItemKudosSlide />
 */
class ReportbackItemKudosSlide extends React.Component {
  constructor(props) {
    super(props);
  }

  render() {
    return (
      <div className="slideshow__slide">
        <div className="container">
          <div className="wrapper">

            <div className="container__row">
              <div className="container__block">
                <h2 className="heading -beta">These members are rocking it already!</h2>
                <p>Tap the heart to show them soome love. We can't wait to see YOUR photos, {this.props.user.info.first_name}!</p>
              </div>
            </div>

            <div className="container__row">
              <div className="container__block">
                {/* @TODO: Include Reportback Items for Kudos-ing here! */}
              </div>
            </div>

          </div>
        </div>
      </div>
    );
  }
}

export default ReportbackItemKudosSlide;
