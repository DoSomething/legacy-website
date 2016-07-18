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
      type: 'campaign',
      campaign: {
        title: 'Pride Over Predjudice',
        tagline: 'Post a selfie to combat anti-immigrant hate speech online.',
        image: 'http://placekitten.com/352/337',
      }
    };

    return (
      <div className="slideshow__slide">
        <div className="container">
          <div className="wrapper">

            <div className="container__row">
              <div className="container__block -primary">
                <h2 className="heading -beta">Woohoo! You're signed up.</h2>
                <p>Nice! By joining {this.props.campaign.title} campaign, you've teamed up with 5.4 million other members who are making an impact on the causes affecting your world.</p>
                <p>As a DoSomething.org member, you're part of something bigger. You're part of a global movement for good.</p>

                <h2 className="heading -beta">Campaigns are a way to make impact.</h2>
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
