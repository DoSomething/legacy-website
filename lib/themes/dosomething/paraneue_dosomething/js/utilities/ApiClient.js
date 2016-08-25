/**
 * ApiClient class to make calls to different services.
 * This could eventually be a class that other classes more
 * specific to certain endpoints extend and define the url
 * request structure on their own so it can accommodate
 * various endpoint URL structures... a boy can dream.
 * For example: class PhoenixApiClient extends ApiClient { .. }
 *
 * @todo when extending this ApiClient to create more specific
 * service clients, could use Object.assign or Lodash extend()
 * to merge header objects with default headers.
 */
class ApiClient {
  constructor(version, host = window.location.hostname, port = window.location.port) {
    this.headers = {
      'Accept': 'application/json',
      'Content-Type': 'application/json',
      'X-CSRF-Token': document.querySelector('meta[name="csrf-token"]').getAttribute('content')
    };
    this.host = host;
    this.port = port === '' ? null : port;
    this.version = `/api/${version}/`;
    this.url = `//${this.host}${this.port ? ':' + this.port : ''}${this.version}`;
  }

  /**
   * Check the HTTP status of API response.
   *
   * @param  {Object} response
   * @return {Object}
   * @throws {Object}
   */
  checkStatus(response) {
    if (response.status >= 200 && response.status < 300) {
      return response;
    } else {
      const error = new Error(response.statusText);

      error.response = response;

      throw error;
    }
  }

  /**
   * Send a DELETE request to the given path URI.
   *
   * @param  {String} path
   * @return {Object}
   */
  delete(path) {
    const url = `${this.url}${path}`;

    // @TODO: see todo in post() method!
    console.log('%c ApiClient DELETE Request: \n' + url,
      'background-color: rgba(105,157,215,0.5); color: rgba(33,70,112,1); line-height: 1.5;'
    );

    // @TODO: lots of repeated code with get() and post().
    // Update to use a send() method (created below) to handle
    // all the fetch stuff, and these other methods simple
    // provide options & configurations, etc.
    return window.fetch(url, {
      method: 'DELETE',
      headers: this.headers,
      credentials: 'same-origin'
    })
      .then(this.checkStatus)
      .then(this.parseJson)
      .catch(function(data) {
        console.log(data);
        console.log('um, there was an error! handle that shizzzzz!');
      });
  }

  /**
   * Convert object with query parameters into string.
   *
   * @param  {Object} query
   * @return {String}
   */
  stringifyQuery(query = {}) {
    let urlParams = [];

    Object.keys(query).forEach((key) => {
      urlParams.push(`${encodeURIComponent(key)}=${encodeURIComponent(query[key])}`);
    });

    if (urlParams.length === 0) {
      return '';
    }

    return `?${urlParams.join('&')}`;
  }

  /**
   * Return the JSON data from API response.
   *
   * @param  {Object} response
   * @return {Object}
   */
  parseJson(response) {
    return response.json();
  }

  /**
   * Send a GET request to the given path URI.
   *
   * @param  {String} path
   * @param  {Object} query
   * @return {Object}
   */
  get(path, query = {}) {
    const url = `${this.url}${path}${this.stringifyQuery(query)}`;

    return window.fetch(url, {
      method: 'GET',
      headers: this.headers,
      credentials: 'same-origin'
    })
      .then(this.checkStatus)
      .then(this.parseJson)
      .catch(function(data) {
        console.log(data);
        console.log('um, there was an error! handle that shizzzzz!');
      });
  }

  /**
   * Send a POST request to the given path URI.
   *
   * @param  {String} path
   * @param  {Object} body
   * @param  {Object} headers
   * @return {Object}
   */
  post(path, body = {}) {
    const url = `${this.url}${path}`;

    // @TODO: little experiment with console output for providing more information when
    // API events are happening. console.log() statement are stripped on Prod builds.
    // Might be useful to have a set of defined styles on a JS object that can be passed
    // through: warning, notice, succes, etc...
    console.log('%c ApiClient POST Request Body: \n' + JSON.stringify(body),
      'background-color: rgba(105,157,215,0.5); color: rgba(33,70,112,1); line-height: 1.5;'
    );

    return window.fetch(url, {
      method: 'POST',
      headers: this.headers,
      credentials: 'same-origin',
      body: JSON.stringify(body)
    })
      .then(this.checkStatus)
      .then(this.parseJson)
      .then(function(response) {
        return response;
    });
  }

  send() {
    // @TODO: setup this send method that all other request methods call.
  }
}

export default ApiClient;
