const React = require('react');

/**
 * Button Component
 * <Button />
 */
const Button = (props) => {
    const classes = ['button'].concat(props.classes);

    if (props.loading === true) {
      classes.push('is-loading');
    }

    if (props.success === true) {
      classes.push('is-successful');
    }

    return (
      <button className={classes.join(' ')} onClick={props.onClick} disabled={props.disabled}>{props.text}</button>
    );
}

Button.defaultProps = {
  disabled: false,
  loading: false,
  success: false,
  text: 'Submit',
};

Button.propTypes = {
  disabled: React.PropTypes.bool,
  loading: React.PropTypes.bool,
  onClick: React.PropTypes.func.isRequired,
  text: React.PropTypes.string,
};

export default Button;
