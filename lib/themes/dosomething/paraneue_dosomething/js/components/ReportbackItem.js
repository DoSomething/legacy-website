const React = require('react');

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
      <div className="photo -stacked -framed" data-reportback-item-id={reportbackItem.id}>
        <figure className="wrapper">
          <img src={reportbackItem.media.uri} alt={reportbackItem.caption} />

          <figcaption className="photo__copy">
            <p className="photo__caption">{reportbackItem.caption}</p>
          </figcaption>
        </figure>
      </div>
    );
  }
}

export default ReportbackItem;
