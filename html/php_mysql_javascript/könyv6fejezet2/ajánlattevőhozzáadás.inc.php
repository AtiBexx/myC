<?php
if (isset($_SESSION['bejelentkezés'])) {
    $ajánlattevőazon = $_POST['ajánlattevőazon'];
    if ((trim($ajánlattevőazon) == '') OR (!is_numeric($ajánlattevőazon)))
    {
        echo "<h2>Sajnáljuk, érvényes ajánlattevői azonosító számot kell megadnod</h2>\n";
    } else
    {
        $vezetéknév = $_POST['vezetéknév'];
        $keresztnév = $_POST['keresztnév'];
        $cím = $_POST['cím'];
        $telefon = $_POST['telefon'];

        $ajánlattevő = new Ajánlattevő($ajánlattevőazon,$vezetéknév,$keresztnév,$cím,$telefon);
        $eredmény = $ajánlattevő->ajánlattevőMentése();
        if ($eredmény)
            echo "<h2>A(z) $ajánlattevőazon új ajánlattevő hozzáadása sikerült</h2>\n";
        else
            echo "<h2>Sajnos hiba történt az ajánlattevő hozzáadása során</h2>\n";
    }
} else {
    echo "<h2>Először jelentkezz be</h2>\n";
}
?>