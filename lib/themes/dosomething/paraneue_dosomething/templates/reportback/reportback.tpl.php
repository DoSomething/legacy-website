<h2>Reportback</h2>
<h3><?php print render($content['node_title']); ?></h3>
<p>User: <?php print render($content['username']); ?></p>

<p><strong><?php print render($content['quantity_count']); ?></strong> <?php print render($content['quantity_label']); ?></p>

<?php if (isset($content['reportback_field_label'])): ?> 
<div>
  <strong><?php print render($content['reportback_field_label']); ?>:</strong>
  <?php if (isset($content['reportback_field_value'])): ?> 
  <?php print render($content['reportback_field_value']); ?>
  <?php endif; ?>
</div>
<?php endif; ?>

<div>
  <strong>Why Participated:</strong>
  <?php print render($content['why_participated']); ?>
</div>

<?php print render($content); ?>
