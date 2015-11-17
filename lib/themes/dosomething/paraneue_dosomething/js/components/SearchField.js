import React, { Component, PropTypes } from 'react';
import classNames from 'classnames';

class SearchField extends Component {

  static propTypes = {
    placeholder: PropTypes.string,
    loading: PropTypes.bool,
    onChange: PropTypes.func.isRequired,
  };

  static defaultProps = {
    placeholder: 'Search...',
    loading: false,
  };

  constructor() {
    super();

    this.onChange = this.onChange.bind(this);
    this.onKeyDown = this.onKeyDown.bind(this);
  }

  onChange(event) {
    event.preventDefault();
    this.props.onChange(event.target.value);
  }

  onKeyDown(event) {
    if (event.keyCode === 13) {
      event.preventDefault();
      document.activeElement.blur();
    }
  }

  render() {
    const classes = classNames('text-field', '-search', {
      'is-loading': this.props.loading,
    });

    return (
      <input type="search" className={classes} placeholder={this.props.placeholder}
             onChange={this.onChange} onKeyDown={this.onKeyDown} />
    );
  }

}

export default SearchField;
