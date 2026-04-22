<table width="100%" cellpadding="3">
<tr>
<?php
    if (!isset($_SESSION['bejelentkezés']))
        echo "<td></td>\n";
    else {
        echo "<td><h3>Üdv, {$_SESSION['bejelentkezés']}</h3></td>\n";
 ?>
</tr>
<tr>
<td><a href="index.php"><strong>Kezdőlap</strong></a></td>
</tr>
<tr>
<td><strong>Ajánlattevők</strong></td>
</tr>
<tr>
<td>&nbsp;&nbsp;&nbsp;<a href="index.php?tartalom=ajánlattevőlista">
<strong>Ajánlattevők listázása</strong></a></td>
</tr>
<tr>
<td>&nbsp;&nbsp;&nbsp;<a href="index.php?tartalom=újajánlattevő">
<strong>Új ajánlattevő hozzáadása</strong></a></td>
</tr>
<tr>
<td><strong>Tételek</strong></td>
</tr>
<tr>
<td>&nbsp;&nbsp;&nbsp;<a href="index.php?tartalom=tétellista">
<strong>Tételek listázása</strong></a></td>
</tr>
<tr>
<td>&nbsp;&nbsp;&nbsp;<a href="index.php?tartalom=újtétel">
<strong>Új tétel hozzáadása</strong></a></td>
</tr>
<tr><td><hr/></td></tr>
<tr><td><a href="index.php?tartalom=kijelentkezés">
<strong>Kijelentkezés</strong></a></td></tr>
<tr>
<td>&nbsp;</td>
</tr>
<tr>
<td>
<form action="index.php" method="post">
<label>Tétel keresése:</label><br>
<input type="text" name="tételazon" size="14" />
<input type="submit" value="keresés" />
<input type="hidden" name="tartalom" value="tételfrissítés">
</form>
</td></tr>
<tr>
<td>
<form action="index.php" method="post">
<label>Ajánlattevő keresése:</label><br>
<input type="text" name="ajánlattevőazon" size="14" />
<input type="submit" value="keresés" />
<input type="hidden" name="tartalom" value="ajánlattevőmegjelenítés">
</form>
</td></tr>
<?php
}
?>
</table>