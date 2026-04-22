<?php

include("Termék.inc.php");

class Üdítő extends Termék {
    private $deciliter;

    public function __construct($név, $érték, $mennyiség, $akció, $méret) {
        parent::__construct($név, $érték, $mennyiség, $akció);
        $this->deciliter = $méret;
    }

    public function __toString() {
        $kimenet = "<p>Termék: " . $this->leírás . "<br>\n";
        $kimenet .= "Ár: " . number_format($this->ár,0) . " Ft<br>\n";
        $kimenet .= "Készlet: " . $this->készlet . "<br>\n";
        $kimenet .= "Akciós: ";
        if ($this->akciós) {
            $kimenet .= "Igen<br>\n";
        } else {
            $kimenet .= "Nem<br>\n";
        }
        $kimenet .= "Kiszerelés (dl): " . $this->deciliter . "</p>\n";
        return $kimenet;
    }


    public function készletfeltöltés($mennyiség) {
        $this->készlet += $mennyiség;
    }
}
?>