import React, { Component, PropTypes } from 'react';
import classNames from 'classnames';

class Result extends Component {

  static propTypes = {
    item: PropTypes.shape({
      name: PropTypes.string,
      city: PropTypes.string,
      state: PropTypes.string,
    }),
    onClick: PropTypes.func,
    selected: PropTypes.bool,
  };

  constructor() {
    super();

    this.onClick = this.onClick.bind(this);
  }

  onClick(event) {
    event.preventDefault();
    this.props.onClick(this.props.item);
  }

  render() {
    const classes = classNames({
      'is-selected': this.props.selected,
    });

    return (
      <a href="#" className={classes} onClick={this.onClick}>
        <span className="schoolfinder-result__name">{ this.props.item.name }</span>
        <em className="schoolfinder-result__location">{ this.props.item.city }, { this.props.item.state }</em>
      </a>
    );
  }
}

export default Result;
