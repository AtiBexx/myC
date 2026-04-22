<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>XSS-teszt</title>
</head>
<body>
<h1>XSS-teszt</h1>
<?php
    $knév = filter_var($_POST['knév'], FILTER_SANITIZE_STRING);
   echo "<p>Szia, $knév!</p>\n";
?>
<h2>Ez itt a teszt vége</h2>
</body>
</html>