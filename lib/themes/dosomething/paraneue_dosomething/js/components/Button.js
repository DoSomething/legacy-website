const React = require('react');

/**
 * Button Component
 * <Button />
 * @param  {[type]} props [description]
 * @return {[type]}       [description]
 */
const Button = (props) => {
    // console.log(props);
    const classes = ['button'].concat(props.classes);

    return (
      <button className={classes.join(' ')} onClick={props.action()}>{props.text}</button>
    );
}

Button.defaultProps = {
  loading: false,
  success: false,
  text: 'Submit',
};

Button.propTypes = {
  action: React.PropTypes.func.isRequired,
  loading: React.PropTypes.bool,
  text: React.PropTypes.string,
};

export default Button;
