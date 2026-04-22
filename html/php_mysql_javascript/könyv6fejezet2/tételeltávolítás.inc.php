<?php
if (isset($_SESSION['bejelentkezés'])) {
    $tételazon = $_POST['tételazon'];
    $tétel = Tétel::tételKeresése($tételazon);
    $eredmény = $tétel->tételEltávolítása();

    if ($eredmény)
        echo "<h2>A(z) $tételazon tétel eltávolítva</h2>\n";
    else
        echo "<h2>Sajnos hiba történt a(z) $tételazon tétel eltávolítása során</h2>\n";
} else {
    echo "<h2>Először jelentkezz be</h2>\n";
}
?>