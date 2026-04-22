<?php
if (isset($_SESSION['bejelentkezés'])) {
    $ajánlattevőazon = $_POST['ajánlattevőazon'];
    $ajánlattevő = Ajánlattevő::ajánlattevőKeresése($ajánlattevőazon);
    $eredmény = $ajánlattevő->ajánlattevőEltávolítása();
    if ($eredmény)
       echo "<h2>A(z) $ajánlattevőazon ajánlattevő eltávolítva</h2>\n";
    else
       echo "<h2>Sajnos hiba történt a(z) $ajánlattevőazon ajánlattevő eltávolítása során</h2>\n";
} else {
    echo "<h2>Először jelentkezz be</h2>\n";
}
?>