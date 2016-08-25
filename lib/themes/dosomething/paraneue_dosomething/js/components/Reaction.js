const React = require('react');

/**
 * Reaction Component with icon and number indicator.
 * <Reaction />
 */
const Reaction = (props) => {
  const classes = ['kudos__icon'];

  if (props.reacted === true) {
    classes.push('is-active');
  }

  return (
    <div>
      <button className={classes.join(' ')} onClick={() => props.onClick(props.termId)}></button>
      <span className="counter">{props.total}</span>
    </div>
  );
}

Reaction.defaultProps = {
  reacted: false,
  total: 0
};

Reaction.propTypes = {
  reacted: React.PropTypes.bool,
  termId: React.PropTypes.string.isRequired,
  total: React.PropTypes.number
};

export default Reaction;
