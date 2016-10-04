const React = require('react');

import Reaction from './Reaction';
import ApiClient from '../utilities/ApiClient';
import setting from '../utilities/Setting';
import { sendEvent } from '../utilities/Analytics';

/**
 * ReactionsList Component
 * <ReactionsList />
 */
class ReactionsList extends React.Component {
  constructor(props) {
    super(props);

    this.apiClient = new ApiClient('v1');
    this.approvedReactions = this.getApprovedReactions();
    this.enabled = setting('dsKudosReactions.enabled', false);

    this.state = {
      reactions: this.setInitialReactions()
    };

    // Bindings
    this.renderReaction = this.renderReaction.bind(this);
    this.toggleReaction = this.toggleReaction.bind(this);
  }

  /**
   * Get all approved reactions from list of available reactions.
   *
   * @return {Object}
   */
  getApprovedReactions() {
    const reactions = {};
    const approvedReactions = setting('dsKudosReactions.approved', []);
    const availableReactions = setting('dsKudosReactions.terms');

    // @TODO: consider possibly using lodash's keyBy() to simplify this:
    // https://lodash.com/docs#keyBy
    approvedReactions.forEach((value) => {
      if (availableReactions.hasOwnProperty(value)) {
        reactions[availableReactions[value]] = value;
      }
    });

    return reactions;
  }

  /**
   * Render a Reaction component.
   *
   * @param  {String} key
   * @param  {Number} index
   * @return {Object}
   */
  renderReaction(key, index) {
    return <li key={index}><Reaction termId={key} total={this.state.reactions[key].total} reacted={this.state.reactions[key].reacted} onClick={this.toggleReaction} /></li>
  }

  /**
   * Collect and setup the initial reactions for the
   * ReactionList component state.
   *
   * @return {Object}
   */
  setInitialReactions() {
    const reactions = {};

    Object.keys(this.approvedReactions).forEach((key) => {
      reactions[key] = {
        id: null,
        reacted: false,
        termId: key,
        termName: this.approvedReactions[key],
        total: 0
      };

      this.props.reactions.forEach((data) => {
        if (data.term.id === key) {
          reactions[key].id = data.current_user.kudos_id;
          reactions[key].reacted = data.current_user.reacted;
          reactions[key].total = data.term.total;
        }
      });
    });

    return reactions;
  }

  /**
   * Toggle the specified reaction state by either creating
   * a new reaction or deleting the existing one.
   *
   * @param  {String} termId
   * @return {void}
   */
  toggleReaction(termId) {
    const reaction = this.state.reactions[termId];
    const reactionId = reaction.id;

    // Delete specified reaction record.
    if (reactionId) {
      sendEvent('onboarding-v2', 'unlike', ReactionsList.analyticsIdentifier);
      this.apiClient.delete(`kudos/${reactionId}`)
        .then((response) => {
          if (response.hasOwnProperty('success')) {
            this.updateReaction(termId);
          }
        });
    }

    // Create new record for reaction.
    if (!reactionId) {
      sendEvent('onboarding-v2', 'like', ReactionsList.analyticsIdentifier);
      this.apiClient.post('kudos', {
        'reportback_item_id': this.props.reportbackItemId,
        'term_ids':[termId]
      }).then((response) => {
        response.forEach((data) => {
          if (data) {
            this.updateReaction(termId, data);
          }
        });
      });
    }
  }

  /**
   * Update the specified reaction in state.
   *
   * @param  {String} termId
   * @param  {Object|null} data
   * @return {void}
   */
  updateReaction(termId, data = null) {
    const reaction = this.state.reactions[termId];

    reaction.reacted = data ? true : false;
    reaction.id = data ? data.kid : null;
    reaction.total = data ? reaction.total + 1 : reaction.total - 1;

    // @TODO: consider looking into not mutating state directly without going
    // through the React API. Maybe use lodash cloneDeep to mutate a clone of
    // object and then setState using that instead.
    this.setState({
      reactions: this.state.reactions
    });
  }

  render () {
    if (!this.enabled) {
      return null;
    }

    return (
      <ul className="form-actions -inline kudos">
        {Object.keys(this.state.reactions).map(this.renderReaction)}
      </ul>
    );
  }
}

ReactionsList.analyticsIdentifier = 'Reactions';

export default ReactionsList;
