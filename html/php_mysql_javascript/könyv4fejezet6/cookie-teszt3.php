<?php
if (isset($_COOKIE['teszt1'])) {
    setcookie("teszt1", "Ez egy tesztcookie", time() + 600);
} else {
    setcookie("teszt1", "", time() - 1);
}
?>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>Cookie törlése</title>
</head>
<body>
<h1>Cookie állapota:</h1>
<?php
    if (isset($_COOKIE['teszt1'])) {
        $adatok = $_COOKIE['teszt1'];
        echo "<p>A cookie be van állítva: $adatok</p>\n";
    } else {
        echo "<p>A cookie nincs beállítva</p>\n";
    }
?>
<a href="cookie-teszt3.php">Kattints ide az újrapróbálkozáshoz</a>
</body>
</html>
