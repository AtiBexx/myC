<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>PHP-űrlapok tesztelése</title>
</head>
<body>
<h1>Az űrlap eredményei:</h1>
<?php
$vnév = $_POST['vnév'];
$knév = $_POST['knév'];
if (isset($_POST['sport'])) {
    $sport = $_POST['sport'];
} else {
    $sport = "nincs megadva";
}
$esszé = $_POST['esszé'];

echo "<h2>Vezetéknév: $vnév</h2>\n";
echo "<h2>Keresztnév: $knév</h2>\n";
echo "<h2>Kedvenc sport: $sport</h2>\n";
echo "<h2>Esszéválasz:</h2>\n";
echo "<p>$esszé</p>\n";
?>
</body>
</html>