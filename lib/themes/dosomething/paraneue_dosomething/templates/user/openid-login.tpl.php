<iframe id="login-iframe" onLoad="iframeReady();" frameborder="0" class="modal-iframe" src="<?php print $url; ?>&chrome=false">
  <h3>Log in to get started!</h3>
  <p><a href="<?php print $url; ?>" class="button">Log In</a></p>
</iframe>
<script>
  // HACK: Handle resizing modal/refreshing page on successful login.
  function iframeReady() {
    // Ask the child page for it's sizing information (since we cannot access document cross-domain).
    document.getElementById('login-iframe').contentWindow.postMessage('sizing?', '*');

    // If we're redirected back to same-origin, then load that in the page.
    // (If the child page is on a different domain, we cannot access the `contentWindow`
    // object, hence why we can safely redirect anytime this is variable is truthy).
    if (document.getElementById('login-iframe').contentWindow.location.href) {
      window.location = document.getElementById('login-iframe').contentWindow.location.href;
    }
  }
</script>

