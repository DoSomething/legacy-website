import CampaignController from '../campaigns/Controller';

const React = require('react');

/**
 * CampaignSlide Component
 * <CampaignSlide />
 */
class CampaignSlide extends React.Component {
  constructor(props) {
    super(props);

    this.controller = new CampaignController();
  }

  render() {

  }
}
