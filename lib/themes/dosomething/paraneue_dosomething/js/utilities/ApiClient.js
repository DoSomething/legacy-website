require('whatwg-fetch');

/**
 * ApiClient class to make calls to different services.
 * This could eventually be a class that other classes more
 * specific to certain endpoints extend and define the url
 * request structure on their own so it can accommodate
 * various endpoint URL structures... a boy can dream.
 * For example: class PhoenixApiClient extends ApiClient { .. }
 */
class ApiClient {

  // @TODO: potentially reconsider order of params...
  // might be best to use default host = window.location.hostname
  constructor(host, version, port = null) {
    this.host = host;
    this.port = port === '' ? null : port;
    this.version = version;
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
   * @param  {Function} callback
   * @return {Object}
   */
  get(path, query = {}, callback) {
    const url = `${this.url}${path}${this.stringifyQuery(query)}`;

    console.log(url);

    fetch(url)
      .then(this.checkStatus)
      .then(this.parseJson)
      .then(function(data) {
        return callback(data);
      }).catch(function(data) {
        console.log('um, there was an error! handle that shizzzzz!');
      });
  }

  /**
   * Send a POST request to the given path URI.
   * @param  {String} path
   * @param  {Object} query
   * @return {Object}
   *
   * @TODO: More to come; build out later!
   */
  post(path, query = {}) {
    return 'hello, and thanks for POSTing!';
  }

}

export default ApiClient;
