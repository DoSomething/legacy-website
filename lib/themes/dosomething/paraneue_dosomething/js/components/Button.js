const React = require('react');

/**
 * Button Component
 * <Button />
 */
const Button = (props) => {
    console.log(props.children);
    const classes = ['button'].concat(props.classes);

    if (props.loading === true) {
      classes.push('is-loading');
    }

    if (props.success === true) {
      classes.push('is-successful');
    }

    return (
      <button className={classes.join(' ')} onClick={props.onClick} disabled={props.disabled}>{props.children}</button>
    );
}

Button.defaultProps = {
  disabled: false,
  loading: false,
  success: false,
  children: 'Submit',
};

Button.propTypes = {
  disabled: React.PropTypes.bool,
  loading: React.PropTypes.bool,
  onClick: React.PropTypes.func.isRequired,
};

export default Button;
