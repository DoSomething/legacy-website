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

    if (props.type) {
      classes.push('-' + props.type);
    }

    if (props.reactive) {
      classes.push('-reactive');
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
  reactive: React.PropTypes.bool,
  type: React.PropTypes.oneOf(['secondary', 'tertiary']),
};

export default Button;
