<?php
$felhasználóazon = $_POST['felhasználóazon'];
$jelszó = $_POST['jelszó'];
$lekérdezés ="SELECT név FROM rendszergazdák WHERE felhasználóiazonosító = ? AND jelszó = SHA2(?,256)";
$adatb = new mysqli("localhost", "ás_felhasználó", "ArveresSeged", "árverés");
$ut = $adatb->prepare($lekérdezés);
$ut->bind_param("ss", $felhasználóazon, $jelszó);
$ut->execute();
$ut->bind_result($név);
$ut->fetch();
if (isset($név)) {
    echo "<h2>Üdvözöl az ÁrverésSegéd</h2>\n";
    $_SESSION['bejelentkezés'] = $név;
    header("Location: index.php");
} else {
    echo "<h2>Sajnos helytelenek a bejelentkezési adatok</h2>\n";
    echo "<a href=\"index.php\">Próbálkozz újra</a>\n";
}
?>