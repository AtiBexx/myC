<?php

class Termék {
    private $leírás;
    private $ár;
    private $készlet;
    private $akciós;

    public function __construct($név, $költség, $mennyiség, $akció) {
        $this->leírás = $név;
        $this->akciós = $akció;
        if ($költség < 0) {
            $this->ár = 0;
        } else {
            $this->ár = $költség;
        }
        if ($mennyiség < 0) {
            $this->készlet = 0;
        } else {
            $this->készlet = $mennyiség;
        }
    }

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

    public function __clone() {
        $this->ár = 0;
        $this->készlet = 0;
        $this->akciós = false;
    }

    public function __toString() {
        $kimenet = "<p>Termék: " . $this->leírás . "<br>\n";
        $kimenet .= "Ár: " . number_format($this->ár,0) . " Ft<br>\n";
        $kimenet .= "Készlet: " . $this->készlet . "<br>\n";
        $kimenet .= "Akciós: ";
        if ($this->akciós) {
            $kimenet .= "Igen</p>\n";
        } else {
            $kimenet .= "Nem</p>\n";
        }
        return $kimenet;
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

    public function leakciózás() {
        $this->akciós = true;
    }
    public function akciómegszüntetése() {
        $this->akciós = false;
    }
}
?>