<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>A PHP foreach utasításának tesztelése</title>
</head>
<body>
<h1>A kedvenceim</h1>
<?php
$kedvencek = array("gyümölcs"=>"banán","zöldség"=>"répa","hús"
     =>"marhasült");
foreach($kedvencek as $kaja => $típus) {
    echo "$kaja - $típus<br>\n";
}
?>
</body>
</html>