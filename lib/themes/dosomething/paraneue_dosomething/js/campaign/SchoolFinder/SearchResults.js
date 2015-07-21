import React, { Component, PropTypes } from 'react';
import includes from 'lodash/collection/includes';
import Result from './Result';

class SearchResults extends Component {

  static propTypes = {
    results: PropTypes.arrayOf(PropTypes.shape({
      gsid: PropTypes.string,
    })),
    selectedItem: PropTypes.shape({
      gsid: PropTypes.string,
    }),
    onClick: PropTypes.func,
  };

  static defaultProps = {
    results: [],
  };

  render() {
    const { results, selectedItem } = this.props;

    // If an item is selected & it's not in results, put it
    // at the top of the list so it's still visible.
    if (selectedItem && !includes(results, selectedItem)) {
      results.unshift(selectedItem);
    }

    const resultList = results.map((result) => {
      return (
        <li key={result.gsid}>
          <Result item={result} onClick={this.props.onClick}
                  selected={selectedItem && (result.gsid === selectedItem.gsid)} />
        </li>
      );
    });

    return <ul className="schoolfinder-results">{resultList}</ul>;
  }
}

export default SearchResults;
