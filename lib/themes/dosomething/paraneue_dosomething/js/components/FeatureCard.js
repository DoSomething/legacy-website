const React = require('react');

/**
 * Card Component
 * <Card />
 */
class FeatureCard extends React.Component {
  constructor(props) {
    super(props);
  }

  render() {
    return (
      <article className="beta-card -white">
        <header className="beta-card__header">
          <div className="beta-card__row">
            <div className="beta-card__block">
              <h1 className="heading -beta -emphasized">{this.props.content.title}</h1>
            </div>
          </div>
        </header>

        <div className="beta-card__body">
          <div className="beta-card__row">
            <div className="beta-card__block -flushed">
              <img src={this.props.content.campaign.image} />
            </div>
          </div>

          <div className="beta-card__row">
            <div className="beta-card__block -centered">
              <h2 className="heading -delta">{this.props.content.campaign.title}</h2>
              <p className="tagline">{this.props.content.campaign.tagline}</p>
              <ul className="form-actions">
                <li><button className="button">Sign Up</button></li>
                <li><a className="button -tertiary" href="#">Show me another</a></li>
              </ul>
            </div>
          </div>
        </div>
      </article>
    )
  }
}

export default FeatureCard;
