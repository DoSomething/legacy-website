const React = require('react');

import ReactionsList from './ReactionsList';
import Setting from '../utilities/Setting';

/**
 * ReportbackItem Component
 * <ReportbackItem />
 */
class ReportbackItem extends React.Component {
  constructor(props) {
    super(props);
  }

  render () {
    const reportbackItem = this.props.data;

    return (
      <div className="photo -stacked -framed">
        <figure className="wrapper">
          <img src={reportbackItem.media.uri} alt={reportbackItem.caption} />

          <figcaption className="photo__copy">
            <p className="photo__caption">{reportbackItem.caption}</p>
          </figcaption>
        </figure>

        <ReactionsList reportbackItemId={reportbackItem.id} reactions={reportbackItem.kudos.data} user={this.props.user} />
      </div>
    );
  }
}

export default ReportbackItem;
