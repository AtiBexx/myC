<?php
if (isset($_SESSION['bejelentkezés'])) {
    $tételazon = $_POST['tételazon'];
    $válasz = $_POST['válasz'];

    if ($válasz == "Tétel frissítése") {
        $tétel = Tétel::tételKeresése($tételazon);
        $tétel->tételazonosító = $_POST['tételazon'];
        $tétel->név = $_POST['név'];
        $tétel->leírás = $_POST['leírás'];
        $tétel->viszonteladóiár = $_POST['viszonteladóiár'];
        $tétel->nyertesajánlattevő = $_POST['nyertesajánlattevő'];
        $tétel->nyertesár = $_POST['nyertesár'];
        $eredmény = $tétel->tételFrissítése();
        if ($eredmény) {
            echo "<h2>A(z) $tételazon tétel frissítve</h2>\n";
        } else {
            echo "<h2>Hiba történt a(z) $tételazon tétel frissítése során</h2>\n";
        }
    } else {
        echo "<h2>A(z) $tételazon tétel frissítése megszakítva</h2>\n";
    }
} else {
    echo "<h2>Először jelentkezz be</h2>\n";
}
?>