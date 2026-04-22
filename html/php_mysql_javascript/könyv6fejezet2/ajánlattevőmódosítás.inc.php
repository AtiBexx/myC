<?php
if (isset($_SESSION['bejelentkezés'])) {
    $ajánlattevőazon = $_POST['ajánlattevőazon'];
    $válasz = $_POST['válasz'];

    if ($válasz == "Ajánlattevő frissítése") {
        $ajánlattevő = Ajánlattevő::ajánlattevőKeresése($ajánlattevőazon);
        $ajánlattevő->ajánlattevőazonosító = $_POST['ajánlattevőazon'];
        $ajánlattevő->vezetéknév = $_POST['vezetéknév'];
        $ajánlattevő->keresztnév = $_POST['keresztnév'];
        $ajánlattevő->cím = $_POST['cím'];
        $ajánlattevő->telefon = $_POST['telefon'];
        $eredmény = $ajánlattevő->ajánlattevőFrissítése();
        if ($eredmény) {
            echo "<h2>A(z) $ajánlattevőazon ajánlattevő frissítve</h2>\n";
        } else {
            echo "<h2>Hiba történt a(z) $ajánlattevőazon ajánlattevő frissítése során</h2>\n";
        }
    } else {
        echo "<h2>A(z) $ajánlattevőazon ajánlattevő frissítése megszakítva</h2>\n";
    }
} else {
    echo "<h2>Először jelentkezz be</h2>\n";
}
?>