<div class="tételek view large-9 medium-8 columns content">
<?php echo "<h3>A tételek, amelyeket $nyertesajánlattevő[0] ajánlattevő nyert meg</h3>\n"; ?>
<section>
<?php $összeg = 0; ?>
<table>
<tr><th>Tételazonosító</th><th>Név</th><th>Leírás</th><th>Nyertes ajánlat</th></tr>
<?php foreach ($tételek as $tétel): ?>
    <?php $összeg = $összeg + $tétel->nyertesár; ?>
    <?php echo "<tr><td>$tétel->tételazonosító</td><td>$tétel->név</td>" ?>
    <?php echo "<td>$tétel->leírás</td><td>$tétel->nyertesár</td></tr>\n"; ?>
<?php endforeach; ?>
<?php echo "<tr><td></td><td></td><td>Összeg</td><td>$összeg</td>\n"; ?>
</table>
<?= $this->Html->link(__('Vissza az ajánlattevők listájához'),['controller' => 'ajánlattevők', 'action' => 'index']) ?>
</section>
</div>