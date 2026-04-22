<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>Képkezelési teszt</title>
</head>
<body>
<h1>A feltöltött kép:</h1>
<?php
$fájl = $_FILES['kép']['tmp_name'];
$kép = file_get_contents($fájl);
$forrásKép = imagecreatefromstring($kép);

$szélesség = imageSX($forrásKép);
$magasság = imageSY($forrásKép);

$újmagasság = 400;
$újszélesség = $újmagasság * ($szélesség / $magasság);

$újKép = imagecreatetruecolor($újszélesség, $újmagasság);
$eredmény = imagecopyresampled($újKép, $forrásKép,
          0, 0, 0, 0,
          $újszélesség, $újmagasság, $szélesség, $magasság);
imagejpeg($újKép, "újkép.jpg");
?>
<img src="újkép.jpg">
</body>
</html>