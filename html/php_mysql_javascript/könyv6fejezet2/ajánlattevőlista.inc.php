<?php

echo "<script language=\"javascript\">\n";
echo "function listbox_dblclick() {\n";
echo "document.ajánlattevők.ajánlattevőmegjelenítés.click() }\n";
echo "</script>\n";

echo "<script language=\"javascript\">\n";
echo "function button_click(célpont) {\n";
echo "if(célpont==0) ajánlattevők.action=\"index.php?tartalom=ajánlattevőmegjelenítés\"\n";
echo "if(célpont==1) ajánlattevők.action=\"index.php?tartalom=ajánlattevőeltávolítás\"\n";
echo "if(célpont==2) ajánlattevők.action=\"index.php?tartalom=ajánlattevőfrissítés\"\n";
echo "}\n";
echo "</script>\n";

echo "<h2>Ajánlattevő kiválasztása</h2>\n";
echo "<form name=\"ajánlattevők\" method=\"post\">\n";
echo "<select ondblclick=\"listbox_dblclick()\" name=\"ajánlattevőazon\" size=\"20\">\n";

$ajánlattevők = Ajánlattevő::ajánlattevőkLekérése();
foreach($ajánlattevők as $ajánlattevő) {
    $ajánlattevőazon = $ajánlattevő->ajánlattevőazonosító;
    $név = $ajánlattevőazon . " - " . $ajánlattevő->vezetéknév . ", " . $ajánlattevő->keresztnév;
    echo "<option value=\"$ajánlattevőazon\">$név</option>\n";
}
echo "</select><br><br>\n";

echo "<input type=\"submit\" onClick=\"button_click(0)\" " .
      "name=\"ajánlattevőmegjelenítés\" value=\"Ajánlattevő megjelenítése\">\n";
echo "<input type=\"submit\" onClick=\"button_click(1)\" " .
      "name=\"ajánlattevőtörlés\" value=\"Ajánlattevő törlése\">\n";
echo "<input type=\"submit\" onClick=\"button_click(2)\" " .
     "name=\"ajánlattevőfrissítés\" value=\"Ajánlattevő frissítése\">\n";
echo "</form>\n";
?>