<h2>Add meg az új ajánlattevő adatait</h2>
<form name="újajánlattevő" action="index.php" method="post">

<table cellpadding="1" border="0">
<tr><td>Ajánlattevő azonosítója:</td><td><input type="text" name="ajánlattevőazon" size="4">
</td></tr>
<tr><td>Vezetéknév:</td><td><input type="text" name="vezetéknév" size="20">
</td></tr>
<tr><td>Keresztnév (nevek):</td><td><input type="text" name="keresztnév" size="50">
</td></tr>
<tr><td>Cím:</td><td><input type="text" name="cím" size="75">
</td></tr>
<tr><td>Telefon:</td><td><input type="text" name="telefon" size="12">
</td></tr>
</table><br>
<input type="submit" value="Új ajánlattevő elküldése">
<input type="hidden" name="tartalom" value="ajánlattevőhozzáadás">
</form>

<script language="javascript">
document.újajánlattevő.ajánlattevőazon.focus();
document.újajánlattevő.ajánlattevőazon.select();
</script>