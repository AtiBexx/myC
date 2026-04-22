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
<h1>Munkamenet-cookie beállítása</h1>
<?php
    $_SESSION['teszt2'] = "Második tesztcookie";
?>
<a href="munkamenetteszt2.php">Kattints ide a folytatáshoz</a>
</body>
</html>

