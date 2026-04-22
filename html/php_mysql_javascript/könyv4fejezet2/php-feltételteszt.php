<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>A PHP-programvezérlés tesztelése</title>
</head>
<body>
<h1>Véletlen számok vizsgálata</h1>
<?php
    $szám = rand(1, 100);
    if ($szám > 50) {
        echo "<h2>A(z) $szám érték túl nagy!</h2>\n";
    } elseif ($szám > 25) {
        echo "<h2>A(z) $szám érték túl közepes!</h2>\n";
    } else {
        echo "<h2>A(z) $szám érték túl kicsi!</h2>\n";
    }
?>
</body>
</html>