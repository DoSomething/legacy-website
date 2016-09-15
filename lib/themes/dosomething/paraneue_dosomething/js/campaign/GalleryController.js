import setting from '../utilities/Setting';
import ApiClient from '../utilities/ApiClient';
import { sortCampaignsByRelevance } from '../campaign/helpers';

class GalleryController {
  constructor() {
    this.campaignsToExclude = setting('dsUser.activity.signups', []);
    this.campaignsApiPage = 1;
    this.apiClient = new ApiClient('v1');
    this.retrievedCampaigns = [];
  }

  filter(campaigns, comparison) {
    return campaigns.filter(campaign => comparison.indexOf(parseInt(campaign.id)) == -1);
  }

  /**
   * Grab campaigns & alter based on given args.
   * @param {Object} args containing the following optional parameters
   *   - {boolean} isStaffPick - Defaults to false.
   *   - {int} page - Defaults to 1.
   *   - {boolean} removeDuplicateResults
   *   - {boolean} sortByRelevance
   *   - {boolean} removeSignups
   * @return {Promise}
   */
  getCampaigns(args) {
    const query = {
      staff_pick: args['isStaffPick'] ? +args['isStaffPick'] : 0, // API requires 1/0 instead of true/false
      page: args['page'] || 1,
    };

    return this.apiClient.get('campaigns', query).then(response => {
      let campaigns = response.data;

      // Remove any campaigns we've already fetched for this gallery.
      if (args['removeDuplicateResults']) {
        campaigns = this.filter(campaigns, this.retrievedCampaigns);
      }
      // Keep track of the campaigns we've recieved.
      this.retrievedCampaigns.concat(campaigns.map(campaign => parseInt(campaign.id)));

      // Use our secret sauce to sort them in order.
      if (args['sortByRelevance']) {
        campaigns = sortCampaignsByRelevance(campaigns);
      }

      if (args['removeSignups']) {
        const signups = setting('dsUser.activity.signups', []);
        campaigns = this.filter(campaigns, signups);
      }

      resolve(campaigns);
    });
  }

  /**
   * Sign the current user up for the specified campaign.
   *
   * @param {int} campaignId
   * @param {string} source
   * @return {Promise}
   */
  signup(campaignId, source) {
    const url = `campaigns/${campaignId}/signup`;
    const data = {source: source};

    return this.apiClient.post(url, data).then(response => {
      resolve();
    });
  }

}

export {GalleryController as default}
