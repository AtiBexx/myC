<?php

echo "<script language=\"javascript\">\n";
echo "function listbox_dblclick() {\n";
echo "document.tételek.tételfrissítés.click() }\n";
echo "</script>\n";

echo "<script language=\"javascript\">\n";
echo "function button_click(célpont) {\n";
echo "if(célpont==0) " .
      "document.tételek.action=\"index.php?tartalom=tételeltávolítás\"\n";
echo "if(célpont==1) " .
      "document.tételek.action=\"index.php?tartalom=tételfrissítés\"\n";
echo "}\n";
echo "</script>\n";

echo "<h2>Tétel kiválasztása</h2>\n";
echo "<form name=\"tételek\" method=\"post\">\n";
echo "<select ondblclick=\"listbox_dblclick()\" " .
      "name=\"tételazon\" size=\"20\">\n";

$tételek= Tétel::tételekLekérése();
foreach($tételek as $tétel) {
    $tételazon = $tétel->tételazonosító;
    $név = $tétel->név;
    $lehetőség = $tételazon . " - " . $név;
    echo "<option value=\"$tételazon\">$lehetőség</option>\n";
}
echo "</select><br><br>\n";

echo "<input type=\"submit\" onClick=\"button_click(0)\" " .
     "name=\"tételtörlés\" value=\"Tétel törlése\">\n";
echo "<input type=\"submit\" onClick=\"button_click(1)\" " .
     "name=\"tételfrissítés\" value=\"Tétel frissítése\">\n";
echo "</form>\n";
?>