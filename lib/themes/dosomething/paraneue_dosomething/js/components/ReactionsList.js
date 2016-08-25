const React = require('react');

import Reaction from './Reaction';
import ApiClient from '../utilities/ApiClient';
import Setting from '../utilities/Setting';

/**
 * ReactionsList Component
 * <ReactionsList />
 */
class ReactionsList extends React.Component {
  constructor(props) {
    super(props);

    this.apiClient = new ApiClient('v1');
    this.approvedReactions = this.getApprovedReactions();
    this.enabled = Setting('dsKudosReactions.enabled', false);

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
    const approvedReactions = Setting('dsKudosReactions.approved', []);
    const availableReactions = Setting('dsKudosReactions.terms');

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
    let reactionId = reaction.id;

    // Delete specified reaction record.
    if (reactionId) {
      this.apiClient.delete(`kudos/${reactionId}`)
        .then((response) => {
          if (response.hasOwnProperty('success')) {
            this.updateReaction(termId);
          }
        });
    }

    // Create new record for reaction.
    if (!reactionId) {
      this.apiClient.post('kudos', {
        'reportback_item_id': this.props.reportbackItemId,
        'user_id': this.props.user.info.drupal_id,
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

export default ReactionsList;
