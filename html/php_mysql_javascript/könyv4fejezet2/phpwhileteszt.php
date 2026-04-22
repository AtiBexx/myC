<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>A PHP while utasításának tesztelése</title>
</head>
<body>
<h1>Bemutatjuk a Beatles-t</h1>
<?php
$csapat = array("John", "Paul", "George", "Ringo");
$számláló = 0;
while ($számláló < 4) {
  echo "A Beatles egyik tagja
            $csapat[$számláló]<br>\n";
  $számláló++;
}
?>
</body>
</html>