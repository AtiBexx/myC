<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>PHP-tesztweblap</title>
<style>
table, th, td {
     border: 1px solid black;
     border-collapse: collapse;
     text-align: center;
}
</style>
</head>
<body>
<h1>A tekecsapatom</h1>
<table>
<tr><th>Tekéző</th><th>Lejátszott játszmák</th><th>Átlag</th></tr>
<?php
$adatb = new mysqli("localhost", "alkfelhasználó1", "H0ssz@bbJelsz0", "alkteszt1");
if (!$adatb) {
    echo "Sajnos nem sikerült csatlakozni az adatbázisszerverhez";
     exit;
}

$lekérdezés = "SELECT tekézőazonosító, név FROM tekézők ORDER BY név";
$eredmény = $adatb->query($lekérdezés);

while($sor = $eredmény->fetch_assoc()) {
    $tekézőazonosító = $sor['tekézőazonosító'];
    $név = $sor['név'];

    $lekérdezés2 = "SELECT COUNT(pontszám) AS játszmák, AVG(pontszám) AS átlag FROM játszmák" .
        " WHERE tekézőazonosító = $tekézőazonosító";
     $eredmény2 = $adatb->query($lekérdezés2);
     $sor2 = $eredmény2->fetch_assoc();
$játszmák = $sor2['játszmák'];
     $átlag = $sor2['átlag'];

     echo "<tr><td>$név</td><td>$játszmák</td><td>$átlag</td>\n";
}
?>
</table>
</body>
</html>