<?php

if (!isset($_REQUEST['ajánlattevőazon']) OR (!is_numeric($_REQUEST['ajánlattevőazon'])))
{
    echo "<h2>Nem jelöltél ki érvényes ajánlattevői azonosítót a megjelenítéshez.</h2>\n";
    echo "<a href=\"index.php?tartalom=ajánlattevőlista\">Ajánlattevők listázása</a>\n";
} else
{
    $ajánlattevőazon = $_REQUEST['ajánlattevőazon'];
    $ajánlattevő = Ajánlattevő::ajánlattevőKeresése($ajánlattevőazon);
    if ($ajánlattevő) {
        echo $ajánlattevő;
        echo "<br><br>\n";
        // A megnyert tételek listázása
        $tételek = Tétel::tételekLekéréseAjánlattevőSzerint($ajánlattevőazon);
        if ($tételek) {
            echo "<b>Megnyert tételek:</b><br>\n";
            echo "<table>\n";
            echo "<tr><td><b>Tétel</b></td><td><b>Név</b></td>" .
            "<td><b>Leírás</b></td><td><b>Összeg</b></td></tr>\n";
            $tételösszeg = 0;
            foreach($tételek as $tétel) {
                printf("<tr><td>%s</td>", $tétel->tételazonosító);
                printf("<td>%s</td>", $tétel->név);
                printf("<td>%s</td>", $tétel->leírás);
                printf("<td>%.0f</td></tr>\n", $tétel->nyertesár);
                $tételösszeg = $tételösszeg + $tétel->nyertesár;
            }
            echo "<tr><td></td><td></td><td><b>Összeg</b></td>";
            printf("<td><b>%.0f</b></td></tr>\n", $tételösszeg);
            echo "</table>\n";
            } else {
            echo "<h2>Jelenleg nincsenek megnyert tételek</h2>\n";
        }
    } else {
        echo "<h2>Sajnos a(z) $ajánlattevőazon ajánlattevő nem található</h2>\n";
    }
}
?>