<?php
/**
 * Returns the HTML for a 404 page.
 *
 * Available Variables
 * - $header: The page header (string).
 * - $subtitle: The page subtitle (string). 
 * - $results: List of related results to display (array).
 * - $search: Indicate if this is specific content or search (boolean).
 * PLANNED
 * - $results_info: Quick description about the results shown (string).
 */
?>
<article>
 
	<header role="banner" class="-centered">
	  <div class="wrapper notfound-header">
	  	<h1 class="__title"><?php print $title ?></h1>  	
	  	<?php print $subtitle ?> <!-- TODO, this should get the same properties of __subtitle -->
	  </div>
	</header>
 
 	<?php if (isset($results)): ?>
	<div class="container notfound-search-results">
		<div class="wrapper">
			<?php if (isset($results_info)): ?>
		  	<p class="center-text"><strong><?php print $results_info ?></strong></p>
		  <?php endif; ?>
		  <?php if ($search): ?>
			  <form class="search-bar">
			  	<input id="bar" type="search" placeholder="Find something..." />
					<input id="button" type="submit" class="btn"></a>
				</form> 
			<?php endif; ?>
			<!--				
 			loop over each result
			create result item 
			-->	
		</div>
	</div>
	<?php endif; ?>
 
</article>