import Button from './Button';

const React = require('react');

/**
 * Signup Card Component
 * <SignupCard />
 */
class SignupCard extends React.Component {
  constructor(props) {
    super(props);

    this.state = {
      actionDisabled: false,
      isSignedUp: false,
      isLoading: false,
    };

    this.delay = null;
    this.signup = this.signup.bind(this);
  }

  signup() {
    this.setState({
      actionDisabled: true,
      isLoading: true
    });
    // this.props.signup --> on callback,
    //    this.setState({isLoading: false,isSignedUp: true});
  }

  render() {
    return (
      <article className="beta-card">
        <div className="beta-card__body">
          <div className="beta-card__row">
            <img src={this.props.image_uri} />
          </div>

          <div className="beta-card__row">
            <div className="beta-card__block -centered">
              <h2 className="heading -delta">{this.props.title}</h2>
              <p className="tagline">{this.props.tagline}</p>
              <ul className="form-actions">
                <li><Button reactive={true} loading={this.state.isLoading} disabled={this.state.actionDisabled} success={this.state.isSignedUp} onClick={this.signup}>Sign Up</Button></li>
              </ul>
            </div>
          </div>
        </div>
      </article>
    )
  }
}

export default SignupCard;
