<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>A PHP-öröklődés tesztelése</title>
</head>
<body>
<h1>Az öröklődés tesztelése az objektumorientált PHP-ban</h1>
<?php

spl_autoload_register(function($osztály) {
    include $osztály . ".inc.php";
});

$termék1 = new Üdítő("Fanta", 200, 10, false, 5);
echo $termék1;

echo "<p>6 flakon megvásárlása...</p>\n";
$termék1->termékVásárlás(6);
echo $termék1;

echo "<p>A készlet feltöltése 4 flakonnal...</p>\n";
$termék1->készletfeltöltés(4);
echo $termék1;

?>
</body>
</html>