<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>PHP OOP-teszt</title>
</head>
<body>
<h1>A PHP objektumorientált beállító és lekérdező metódusainak tesztelése</h1>
<?php
class Termék {
    private $leírás;
    private $ár;
    private $készlet;
    private $akciós;

    public function __set($név, $érték) {
        if ($név == "ár" && $érték < 0) {
            echo "<p>A beállított ár érvénytelen</p>\n";
            $this->ár = 0;
        } elseif ($név == "készlet" && $érték < 0) {
            echo "<p>A beállított készlet érvénytelen: $érték</p>\n";
        } else {
            $this->$név = $érték;
        }
    }

    public function __get($név) {
        return $this->$név;
    }

    public function termékVásárlás($mennyiség) {
        if ($this->készlet >= $mennyiség) {
            $this->készlet -= $mennyiség;
        } else {
            echo "<p>Sajnos a kért készlet érvénytelen:
                $mennyiség</p>\n";
            echo "<p>Csak $this->készlet
                maradt</p>\n";
        }
    }
}

$termék1 = new Termék();
$termék1->leírás = "Répa";
$termék1->ár = 150;
$termék1->készlet = 5;
$termék1->akciós = false;

echo "<p>$termék1->készlet $termék1->leírás hozzáadva</p>\n";

echo "<p>4 répa megvásárlása...</p>\n";
$termék1->termékVásárlás(4);
echo "<p>$termék1->leírás készlete most már $termék1->készlet</p>\n";

echo "<p>Megpróbáljuk -1-re állítani a répa készletét:</p>\n";
$termék1->készlet = -1;

echo "<p>Most megpróbálunk megvásárolni 10 répát...</p>\n";
$termék1->termékVásárlás(10);
echo "<p>$termék1->leírás készlete most már $termék1->készlet</p>\n";
?>
</body>
</html>