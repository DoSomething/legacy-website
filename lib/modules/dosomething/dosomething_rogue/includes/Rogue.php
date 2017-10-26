<?php

use DoSomething\Gateway\Common\RestApiClient;
use DoSomething\Gateway\ForwardsTransactionIds;

class Rogue extends RestApiClient {
  use ForwardsTransactionIds;

  /**
   * The class name of the transaction framework bridge.
   *
   * @var string
   */
  protected $transactionBridge = Phoenix\Auth\PhoenixTransactionBridge::class;

  /**
   * Send a GET request to return all reportbacks matching a given
   * query from Rogue.
   *
   * @param array $inputs
   * @return array - JSON response
   */
  public function getAllReportbacks($inputs = [])
  {
    $response = $this->get('v1/reportbacks', $inputs);

    return $response;
  }

  /**
   * Send a POST request of a reaction to be saved/deleted in Rogue.
   *
   * @param array $data
   * @return array - JSON response
   */
  public function postReaction($data)
  {
    $response = $this->post('v2/reactions', $data);

    return $response;
  }

  /**
   * Send a POST request of the reportback to be saved in Rogue.
   *
   * @param string $baseurl
   * @param array $data
   * @return array - JSON response
   */
  public function postReportback($data)
  {
    $response = $this->post('v2/posts', $data);

    return $response;
  }

  /**
   * Send a PUT request of the updated reportback to be saved in Rogue.
   *
   * @param string $baseurl
   * @param array $data
   * @return array - JSON response
   */
  public function updateReportback($data)
  {
    $response = $this->put('v2/reviews', $data);

    return $response;
  }

  /**
   * Send a POST request of the signup to be saved in Rogue.
   *
   * @param array $data
   * @return array - JSON response
   */
  public function postSignup($data)
  {
    $response = $this->post('v2/signups', $data);

    return $response;
  }

  /**
   * Send a POST request of the signup to be saved in Rogue.
   *
   * @param array $data
   * @return array - JSON response
   */
  public function postReview($data)
  {
    $response = $this->post('v2/reviews', $data);

    return $response;
  }

  /**
   * Send a GET request to return all reportbacks matching a given
   * query from Rogue.
   *
   * @param array $inputs
   * @return array - JSON response
   */
  public function getActivity($inputs = [])
  {
    $response = $this->get('v2/activity', $inputs);

    return $response;
  }

  /**
   * Send a GET request to return all posts matching a given
   * query from Rogue.
   *
   * @param array $inputs
   * @return array - JSON response
   */
  public function getPosts($inputs = [])
  {
    $response = $this->get('v2/posts', $inputs);

    return $response;
  }

  /**
   * Send a POST request to add a the given tag to the given post in Rogue
   *
   * @param array $data
   * @return array - JSON response
   */
  public function postTag($data)
  {
    $response = $this->post('v2/tags', $data);

    return $response;
  }

  /**
   * Send a POST request to create a new post in Rogue
   *
   * @param array $data
   * @return array - JSON response
   */
  public function postPost($data)
  {
    $response = $this->post('v2/posts', $data);

    return $response;
  }
}
