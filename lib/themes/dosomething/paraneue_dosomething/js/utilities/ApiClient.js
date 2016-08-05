/**
 * ApiClient class to make calls to different services.
 * This could eventually be a class that other classes more
 * specific to certain endpoints extend and define the url
 * request structure on their own so it can accommodate
 * various endpoint URL structures.
 * For example: class PhoenixApiClient extends ApiClient { .. }
 */
class ApiClient {

  constructor(host, version, port = '') {
    console.log(host);
    console.log(version);
    console.log(port);
    this.api = {
      host,
      port,
      version
    };

    // this.api.port = port;
    // this.api.verstion = version;
    // this.api.url = `http://${this.api.host}${this.api.port}${this.api.version}`;
  }

  request(endpoint) {
    return 'hello';
  }

}

export default ApiClient;
