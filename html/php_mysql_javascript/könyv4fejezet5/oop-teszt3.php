<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>Teljes PHP OOP-teszt</title>
</head>
<body>
<h1>A PHP-osztály tesztelése</h1>
<?php

spl_autoload_register(function($osztály) {
    include $osztály . ".inc.php";
});

$termék1 = new Termék("Répa", 400, 10, false);
echo "<p>A következő termék létrehozása:</p>\n";
echo $termék1;

$termék2 = new Termék("Padlizsán", 200, 5, true);
echo "<p>A következő termék létrehozása:</p>\n";
echo $termék2;

echo "<p>$termék1->leírás leakciózása:</p>\n";
$termék1->ár = 300;
$termék1->leakciózás();
echo "<p>A termék új állapota:</p>\n";
echo $termék1;
?>
</body>
</html>