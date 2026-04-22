<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>PHP-cookie tesztelése</title>
</head>
<body>
<h1>A tesztcookie kinyerése</h1>
<?php
if (isset($_COOKIE['teszt1'])) {
   $adatok = $_COOKIE['teszt1'];
    echo "<p>A cookie be lett állítva: $adatok</p>\n";
} else {
    echo "<p>Sajnos nem sikerült megtalálni a cookie-t</p>\n";
}
?>
</body>
</html>
