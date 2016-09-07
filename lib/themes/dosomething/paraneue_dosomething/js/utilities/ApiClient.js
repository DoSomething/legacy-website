const merge = require('lodash/merge');

/**
 * ApiClient class to make calls to different services.
 * This could eventually be a class that other classes more
 * specific to certain endpoints extend and define the url
 * request structure on their own so it can accommodate
 * various endpoint URL structures... a boy can dream.
 * For example: class PhoenixApiClient extends ApiClient { .. }
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
    this.hostname = `//${this.host}${this.port ? ':' + this.port : ''}`;
    this.url = `${this.hostname}${this.version}`;
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

    return this.send('DELETE', url);
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

    return this.send('GET', url);
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

    return this.send('POST', url, {
      body: JSON.stringify(body)
    });
  }

  /**
   * Send an API request using fetch() and return response.
   *
   * @param  {String} method
   * @param  {String} url
   * @param  {Object} options
   * @return {Promise}
   */
  send(method, url, options = {}) {
    const defaults = {
      method: method,
      headers: this.headers,
      credentials: 'same-origin'
    };

    merge(defaults, options);

    // Developer Output:
    console.log('%c ApiClient %s Request:',
      'background-color: rgba(105,157,215,0.5); color: rgba(33,70,112,1); display: block; font-weight: bold; line-height: 1.5;',
      method
    );
    console.log('URL: \n%s', url);
    console.log('Options: \n%o', defaults);

    return window.fetch(url, defaults)
      .then(this.checkStatus)
      .then(this.parseJson)
      .catch((data) => {
        console.log(data);
        console.error('um, there was an error! handle that shizzzzz!');
      });
  }
}

export default ApiClient;
