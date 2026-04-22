<?php
$ajánlattevőazon = $_POST['ajánlattevőazon'];
$ajánlattevő = Ajánlattevő::ajánlattevőKeresése($ajánlattevőazon);
if ($ajánlattevő) {
    echo "<h2>A(z) $ajánlattevőazon ajánlattevő frissítése</h2>\n";
    echo "<form name=\"ajánlattevő\" action=\"index.php\" method=\"post\">\n";
    echo "<table>\n";
    echo "<tr><td>Ajánlattevő azonosítója</td><td>$ajánlattevő->ajánlattevőazonosító</td></tr>\n";
    echo "<tr><td>Vezetéknév</td><td><input type=\"text\" name=\"vezetéknév\" " .
        "value=\"$ajánlattevő->vezetéknév\"></td></tr>\n";
    echo "<tr><td>Keresztnév</td><td><input type=\"text\" " .
          "name=\"keresztnév\" value=\"$ajánlattevő->keresztnév\"></td></tr>\n";
    echo "<tr><td>Cím</td><td><input type=\"text\" " .
          "name=\"cím\" value=\"$ajánlattevő->cím\"></td></tr>\n";
    echo "<tr><td>Telefon</td><td><input type=\"text\" " .
          "name=\"telefon\" value=\"$ajánlattevő->telefon\"></td></tr>\n";
    echo "</table><br><br>\n";
    echo "<input type=\"submit\" name=\"válasz\" value=\"Ajánlattevő frissítése\"></td></tr>\n";
    echo "<input type=\"submit\" name=\"válasz\" value=\"Mégse\"></td></tr>\n";
    echo "<input type=\"hidden\" name=\"ajánlattevőazon\" value=\"$ajánlattevőazon\"></td></tr>\n";
    echo "<input type=\"hidden\" name=\"tartalom\" value=\"ajánlattevőmódosítás\">\n";
    echo "</form>\n";
} else {
    echo "<h2>Sajnos a(z) $ajánlattevőazon ajánlattevő nem található</h2>\n";
}
?>
<script language="javascript">
document.ajánlattevő.vezetéknév.focus();
document.ajánlattevő.vezetéknév.select();
</script>