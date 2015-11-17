import React, { Component, PropTypes } from 'react';

class Checkbox extends Component {

  static propTypes = {
    label: PropTypes.string,
    checked: PropTypes.bool,
    onClick: PropTypes.func,
  };

  render() {
    return (
      <label className="option -checkbox" onClick={this.props.onClick}>
        <input type="checkbox" className="form-checkbox" value={this.props.checked} />
        <span className="option__indicator" />
        {this.props.label}
      </label>
    );
  }
}

export default Checkbox;
