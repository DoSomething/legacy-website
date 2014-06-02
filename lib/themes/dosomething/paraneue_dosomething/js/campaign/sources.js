define(function() {
  "use strict";

  var $ = require("jquery");


// <?php if (isset($fact_sources)): ?>
// <section class="sources">
//   <h3 class="js-toggle-sources secondary">Sources</h3>
//   <ul class="legal">
//     <?php foreach ($fact_sources as $key => $source): ?>
//       <li><sup><?php print ($key + 1); ?></sup> <?php print $source; ?></li>
//     <?php endforeach; ?>
//   </ul>
// </section>
// <?php endif; ?>



  // Toggle visibility of fact sources
  $(".js-toggle-sources").on("click", function(e) {
    e.preventDefault();



    // Toggle visibility of fact sources wrapper
    // $(".sources").slideToggle();
  });
});
