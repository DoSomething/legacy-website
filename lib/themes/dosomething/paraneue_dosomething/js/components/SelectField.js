import React, { Component, PropTypes } from 'react';
import map from 'lodash/collection/map';

class SelectField extends Component {

  static propTypes = {
    options: PropTypes.object,
    selected: PropTypes.string,
    onChange: PropTypes.func,
  };

  static defaultProps = {
    options: [],
    selected: null,
  };

  constructor() {
    super();

    this.onChange = this.onChange.bind(this);
  }

  onChange(event) {
    event.preventDefault();
    this.props.onChange(event.target.value);
  }

  render() {
    const options = map(this.props.options, (value, key) => {
      return <option key={key} value={key}>{value}</option>;
    });

    return (
      <div className="select">
        <select value={this.props.selected} onChange={this.onChange}>
          { options }
        </select>
      </div>
    );
  }

}

export default SelectField;
