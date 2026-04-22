<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>PHP-függvény tesztelése</title>
</head>
<body>
<?php
function faktoriális($érték1) {
    $faktoriális = 1;
    $számláló = 1;
    while ($számláló <= $érték1) {
        $faktoriális *= $számláló;
    $számláló++;
    }
    return $faktoriális;
}
?>
<h1>Faktoriálisok kiszámítása</h1>
<?php
echo "10 faktoriálisa " . faktoriális(10) . "<br>\n";
echo "5 faktoriálisa " . faktoriális(5) . "<br>\n";
?>
</body>
</html>