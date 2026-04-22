<?php
if (isset($_SESSION['bejelentkezés'])) {
    $tételazon = $_POST['tételazon'];
    if ((trim($tételazon) == '') OR (!is_numeric($tételazon)))
    {
        echo "<h2>Sajnáljuk, érvényes tételazonosító számot kell megadnod</h2>\n";
    } else
    {
        $név = $_POST['név'];
        $leírás = $_POST['leírás'];
        $viszonteladóiár = $_POST['viszonteladóiár'];
        $nyertesajánlattevő = $_POST['nyertesajánlattevő'];
        $nyertesár = $_POST['nyertesár'];

        $tétel = new Tétel($tételazon, $név, $leírás, $viszonteladóiár,
                    $nyertesajánlattevő, $nyertesár);
        $eredmény = $tétel->tételMentése();
        if ($eredmény)
            echo "<h2>A(z) $tételazon új tétel hozzáadása sikerült</h2>\n";
        else
            echo "<h2>Sajnos hiba történt a tétel hozzáadása során</h2>\n";
    }
} else {
    echo "<h2>Először jelentkezz be</h2>\n";
}
?>