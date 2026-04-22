<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>PHP OOP-teszt</title>
</head>
<body>
<h1>Objektumorientált PHP-kód tesztelése</h1>
<?php
class Termék {
    public $leírás;
    public $ár;
    public $készlet;
    public $akciós;

    public function termékVásárlás($mennyiség) {
        $this->készlet -= $mennyiség;
    }
}

$termék1 = new Termék();
$termék1->leírás = "Répa";
$termék1->ár = 150;
$termék1->készlet = 10;
$termék1->akciós = false;
echo "<p>$termék1->leírás hozzáadva</p>\n";

$termék2 = new Termék();
$termék2->leírás = "Padlizsán";
$termék2->ár = 200;
$termék2->készlet = 5;
$termék2->akciós = true;
echo "<p>$termék2->leírás hozzáadva</p>\n";

echo "<p>4 répa megvásárlása...</p>\n";
$termék1->termékVásárlás(4);
echo "<p>$termék1->leírás fennmaradó készlete:
        $termék1->készlet</p>\n";
echo "<p>$termék2->leírás készlete továbbra is
        $termék2->készlet</p>\n";
?>
</body>
</html>