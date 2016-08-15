import FeatureCard from './FeatureCard';

const React = require('react');

/**
 * ContextSlide Component
 * <ContextSlide />
 */
class ContextSlide extends React.Component {
  constructor(props) {
    super(props);
  }

  render() {
    // @TOOD: temporarily hardcoding for now.
    const card = {
      title: 'Trending Now',
      type: 'campaign'
    };

    const competition = Drupal.settings.dosomethingSignup ? Drupal.settings.dosomethingSignup.competition : null;
    const displayCompetitionMessage = competition && competition.joined && competition.messages;

    return (
      <div className={this.props.displayClasses.join(' ')}>
        <div className="container">
          <div className="wrapper">

            <div className="container__row">
              <div className="container__block -primary">
                <h2 className="heading -gamma">Woohoo! You're signed up.</h2>
                {displayCompetitionMessage ? <p>{competition.messages.confirmation}</p> : ''}
                <p>By joining {this.props.campaign.title} campaign, you've teamed up with 5.3 million other members who are making an impact on the causes affecting your world.</p>
                <p>As a DoSomething.org member, you're part of something bigger. You're part of a global movement for good.</p>

                <h2 className="heading -gamma">Campaigns are a way to make impact.</h2>
                <p>You'll get all the tools you need to create impact. You've already joined {this.props.campaign.title}. Now sign up for other popular campaigns!</p>
              </div>

              <div className="container__block -secondary">
                <FeatureCard content={card} />
              </div>
            </div>

          </div>
        </div>
      </div>
    );
  }
}

export default ContextSlide;
