<?php
if (!isset($_POST['tételazon']) OR (!is_numeric($_POST['tételazon']))) {
    echo "<h2>Nem jelöltél ki érvényes tételazonosítót</h2>\n";
    echo "<a href=\"index.php?tartalom=ajánlattevőlista\">Ajánlattevők listázása</a>\n";
} else {
    $tételazon = $_POST['tételazon'];
    $tétel = Tétel::tételKeresése($tételazon);
    if ($tétel) {
        echo "<h2>A(z) $tétel->tételazonosító frissítése</h2>\n";
        echo "<form name=\"tételek\" action=\"index.php\" method=\"post\">\n";
        echo "<table>\n";
        echo "<tr><td>Tételazonosító</td><td>$tétel->tételazonosító</td></tr>\n";
        echo "<tr><td>Név</td><td><input type=\"text\" name=\"név\" " .
             "value=\"$tétel->név\"></td></tr>\n";
        echo "<tr><td>Leírás</td><td><input type=\"text\" " .
             "name=\"leírás\" value=\"$tétel->leírás\"></td></tr>\n";
        echo "<tr><td>Viszonteladói ár</td><td><input type=\"text\" " .
             "name=\"viszonteladóiár\" value=\"$tétel->viszonteladóiár\"></td></tr>\n";
        echo "<tr><td>Nyertes ajánlattevő</td><td><input type=\"text\" " .
             "name=\"nyertesajánlattevő\" value=\"$tétel->nyertesajánlattevő\"></td></tr>\n";
        echo "<tr><td>Nyertes ár</td><td><input type=\"text\" " .
             "name=\"nyertesár\" value=\"$tétel->nyertesár\"></td></tr>\n";
        echo "</table><br><br>\n";
        echo "<input type=\"submit\" name=\"válasz\" " .
             "value=\"Tétel frissítése\">\n";
        echo "<input type=\"submit\" name=\"válasz\" value=\"Mégse\"></td></tr>\n";
        echo "<input type=\"hidden\" name=\"tételazon\" value=\"$tételazon\">\n";
        echo "<input type=\"hidden\" name=\"tartalom\" value=\"tételmódosítás\">\n";
        echo "</form>\n";
    } else {
        echo "<h2>Sajnos a(z) $tételazon tétel nem található</h2>\n";
        echo "<a href=\"index.php?tartalom=ajánlattevőlista\">Ajánlattevők listázása</a>\n";
    }
}
?>
<script language="javascript">
document.tételek.nyertesajánlattevő.focus();
document.tételek.nyertesajánlattevő.select();
</script>