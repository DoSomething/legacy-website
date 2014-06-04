<?php
/**
 * Returns the HTML for Fact Page list.
 *
 * Available Variables
 * - $links: Array of links, keyed by the cause name.
 */
?>

<article id="node-<?php print $node->nid; ?>" class="campaign-group <?php print $classes; ?> clearfix"<?php print $attributes; ?>>

	<section class="container">
		<div class="wrapper">
			<div class="container__body">
				<?php foreach ($links as $cause => $fact_pages): ?>
				  <h2 class="container__title inline--alt-color"><?php print $cause; ?></h2>
				  <ul>
				    <?php foreach ($fact_pages as $link): ?>
				    <li><?php print $link; ?></li>
				    <?php endforeach ; ?>
				  </ul>
				<?php endforeach; ?>
				</div>
		</div>
	</section>

</article>