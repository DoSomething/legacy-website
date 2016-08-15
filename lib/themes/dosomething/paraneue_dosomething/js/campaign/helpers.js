/**
 * Checks if the given campaign is still open
 * @param {object|null} campaign
 * @return {bool}
 */
export function isCampaignOpen(campaign = null) {
  if (!campaign) {
    return false;
  }

  return campaign.status === 'active';
}

/**
 * Checks if the given campaign is a staff pick
 *
 * @param {object|null} campaign
 * @return {bool}
 */
export function isStaffPick(campaign = null) {
  if (!campaign) {
    return false;
  }

  return campaign.staff_pick;
}

/**
 * Check if specified campaign has a sponsor associated.
 *
 * @param  {object|null} campaign
 * @return {bool}
 */
export function checkForSponsor(campaign = null) {
  if (!campaign) {
    return false;
  }

  const partners = campaign.affiliates.partners;

  if (partners.length < 1) {
    return false;
  }

  for (let partner of partners) {
    // Only return true when one of the partners has a sponsor.
    if (partner.sponsor) {
      return true;
    }
  }

  return false;
}

/**
 * Sort campaigns based on time commitment.
 *
 * @param  {object} a
 * @param  {object} b
 * @return {int}
 */
export function rankCampaignsByTime(a, b) {
  return a.time_commitment - b.time_commitment;
}

/**
 * Sorts a given array of campaigns in the most relevant order.
 * This means staff picks have priority, followed by sponsor.
 * In each of those categories, we should sort by the time commitment.
 *
 * @param  {Array} campaigns
 * @return {Array} sortedCampaigns
 */
export function sortCampaignsByRelevance(campaigns = []) {
  // First remove any closed campaigns.
  campaigns = campaigns.filter(isCampaignOpen);

  // Let's grab all staff picks.
  let staffPicks = campaigns.filter(isStaffPick);

  // We'll sort sponsored staff picks first.
  const sponsoredStaffPicks = staffPicks.filter(checkForSponsor).sort(rankCampaignsByTime);

  // Then the rest of the staff picks.
  // This removes sponsoredStaffPicks from staffPicks and ranks by time.
  staffPicks = staffPicks.filter(campaign => !checkForSponsor(campaign)).sort(rankCampaignsByTime);

  // Next we'll look at sponsored campaigns that aren't staff picks.
  // This removes staff picks from the campaigns list & grabs all sponsored campaigns.
  const sponsoredCampaigns = campaigns.filter(campaign => !isStaffPick(campaign)).filter(checkForSponsor);
  sponsoredCampaigns.sort(rankCampaignsByTime);

  // Finally we look at all the remaining campaigns.
  // This removes all staff picks & sponsored campaigns from the campaigns parameter.
  campaigns = campaigns.filter(campaign => !isStaffPick(campaign)).filter(campaign => !checkForSponsor(campaign));
  campaigns.sort(rankCampaignsByTime);

  // Merge all of the sorted arrays into one.
  // TODO: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/Spread_operator
  return sponsoredStaffPicks.concat(staffPicks).concat(sponsoredCampaigns).concat(campaigns);
}
