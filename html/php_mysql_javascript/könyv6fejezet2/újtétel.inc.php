<h2>Add meg az új tétel adatait</h2>
<form name="újtétel" action="index.php" method="post">

<table cellpadding="1" border="0">
<tr><td>Tétel azonosítója:</td><td><input type="text" name="tételazon" size="4">
</td></tr>
<tr><td>Név:</td><td><input type="text" name="név" size="20">
</td></tr>
<tr><td>Leírás:</td><td><input type="text" name="leírás" size="50">
</td></tr>
<tr><td>Viszonteladói ár:</td><td><input type="text" name="viszonteladóiár" size="10">
</td></tr>
<tr><td>Nyertes ajánlattevő:</td><td><input type="text" name="nyertesajánlattevő" size="4">
</td></tr>
<tr><td>Nyertes ár:</td><td><input type="text" name="nyertesár" size="10">
</td></tr>
</table><br>
<input type="submit" value="Új tétel elküldése">
<input type="hidden" name="tartalom" value="tételhozzáadás">
</form>

<script language="javascript">
document.újtétel.tételazon.focus();
document.újtétel.tételazon.select();
</script>