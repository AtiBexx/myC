<?php
if (!isset($_SESSION['bejelentkezés'])) {
?>
<h2>Kérjük, jelentkezz be</h2><br>
<form name="bejelentkezés" action="index.php" method="post">
<label>Felhasználói azonosító</label>
<input type="text" name="felhasználóazon" size="10" />
<br>
<br>
<label>Jelszó</label>
<input type="password" name="jelszó" size="10" />
<br>
<br>
<input type="submit" value="Bejelentkezés">
<input type="hidden" name="tartalom" value="ellenőrzés">
</form>
<?php
} else {
    echo "<h2>Üdvözöl az ÁrverésSegéd</h2>\n";
    echo "<br><br>\n";
    echo "<p>Ez a program nyomon követi az ajánlattevők és az aukciós tételek adatait</p>\n";
    echo "<p>Kérjük, használd a navigációs sáv hivatkozásait</p>\n";
    echo "<p>Kérjük, NE HASZNÁLD a böngésző navigációs gombjait!</p>\n";
}
?>
<script language="javascript">
document.bejelentkezés.felhasználóazon.focus();
document.bejelentkezés.felhasználóazon.select();
</script>