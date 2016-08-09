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
    if (partner.sponsor) {
      return true;
    }
  }

  return false;
}

/**
 * Sort and rank campaigns by time commitment and if it has a sponsor.
 *
 * @param  {object} a
 * @param  {object} b
 * @return {int}
 */
export function rankCampaigns(a, b) {
  const aScore = a.time_commitment - (checkForSponsor(a) ? 1 : 0);
  const bScore = b.time_commitment - (checkForSponsor(b) ? 1 : 0);

  return aScore - bScore;
}
