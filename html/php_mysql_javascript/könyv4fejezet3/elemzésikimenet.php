<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>A sztringelemzési teszt eredményei</title>
</head>
</body>
<h1>A keresőszavak eredményei</h1>
<?php
$keresés = $_POST['keresés'];
$szavak = str_getcsv($keresés);

foreach ($szavak as $szó) {
   $kifejezés = trim($szó);
   echo "<p>Keresőszó: '$kifejezés'</p>\n";
}
?>
</body>
</html>