import React, { Component, PropTypes } from 'react';
import { ajax } from 'jquery';
import isEmpty from 'lodash/lang/isEmpty';

import SelectField from '../../components/SelectField';
import SearchField from '../../components/SearchField';
import SearchResults from './SearchResults';
import Checkbox from '../../components/Checkbox';
import setting from '../../utilities/Setting';

class SchoolFinder extends Component {

  static propTypes = {
    areas: PropTypes.object,
    areaLabel: PropTypes.string,
  };

  constructor() {
    super();

    this.state = {
      state: 'CT',
      query: '',
      optedOut: false,
    };

    this.onSelectState = this.onSelectState.bind(this);
    this.onSearch = this.onSearch.bind(this);
    this.onOptOut = this.onOptOut.bind(this);
    this.onSelectResult = this.onSelectResult.bind(this);
  }

  onSelectState(state) {
    this.setState({ state: state });
    this.getData(this.state.query, state);
  }

  onSearch(query) {
    this.setState({ query: query });
    this.getData(query, this.state.state);
  }

  onSelectResult(item) {
    this.setState({ selected: item });
  }

  onOptOut(event) {
    event.preventDefault();
    this.setState({ optedOut: !this.state.optedOut });
  }

  getData(query, state) {
    const endpoint = setting('dosomethingUser.schoolFinderAPIEndpoint', 'http://lofischools.herokuapp.com/search');
    if (isEmpty(query) || isEmpty(state)) return this.setState({ error: false, results: [] });

    ajax({
      dataType: 'json',
      url: `${endpoint}?state=${state}&query=${query}&limit=25`,
    }).done((data) => {
      this.setState({ error: false, results: data.results, canShowMore: data.meta.more_results }); // jshint ignore:line
    }).fail(() => {
      this.setState({ error: true });
    });
  }

  render() {
    return (
      <div>
        <SelectField options={this.props.areas} label={this.props.areaLabel} onChange={this.onSelectState} />
        <SearchField loading={false} onChange={this.onSearch} placeholder="Find your school by name..." />
        <SearchResults results={this.state.results} selectedItem={this.state.selected} onClick={this.onSelectResult} />
        <Checkbox checked={this.state.optedOut} onClick={this.onOptOut} label="I'm not doing this at school." />
        {this.state.optedOut ? <div className="messages">Confirmation message.</div> : null}
      </div>
    );
  }
}

function init(el = document.getElementById('edit-school-finder')) {
  if (!el) return;

  const areas = el.getAttribute('data-administrative-areas');
  const areaLabel = el.getAttribute('data-administrative-area-label');

  React.render(<SchoolFinder areas={JSON.parse(areas)} areaLabel={areaLabel} />, el);
}

export default { SchoolFinder, init };
