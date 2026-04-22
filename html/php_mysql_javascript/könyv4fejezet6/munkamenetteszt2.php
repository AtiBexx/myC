<?php
session_start();
?>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>A munkamenet-cookie-k tesztelése</title>
</head>
<body>
<h1>A munkamenet-cookie kinyerése</h1>
<?php
    if (isset($_SESSION['teszt2'])) {
        $adatok = $_SESSION['teszt2'];
        echo "<p>Munkamenet-cookie: $adatok</p>\n";
    } else {
        echo "<p>Hiba történt a munkamenet-
                cookie elérése közben</p>\n";
    }
?>
<a href="munkamenetteszt1.php">Vissza a kezdőlapra</a>
</body>
</html>