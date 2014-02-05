<h2>Reportback</h2>
<h3><?php print render($content['node_title']); ?></h3>
<p><?php print render($content['username']); ?></p>

<?php if (isset($edit_link) || isset($delete_link)): ?>
<nav class"tabs">
  <ul>
    <?php if (isset($edit_link)): ?>
    <li><?php print $edit_link; ?></li>
    <?php endif; ?>
    <?php if (isset($delete_link)): ?>
    <li><?php print $delete_link; ?></li>
    <?php endif; ?>
  </ul>
  <?php endif; ?>
</nav>

<p><strong><?php print render($content['quantity_count']); ?></strong> <?php print render($content['quantity_label']); ?></p>
<p><?php print render($content['why_participated']); ?></p>

<?php if (isset($content['num_participants'])): ?> 
<p><?php print render($content['num_participants']); ?> participants</p>
<?php endif; ?>

<?php print render($content); ?>
