<?php
class Ajánlattevő {
    public $ajánlattevőazonosító;
    public $vezetéknév;
    public $keresztnév;
    public $cím;
    public $telefon;

    function __construct($ajánlattevőazonosító, $vnév, $knév, $cím, $telefon) {
        $this->ajánlattevőazonosító = $ajánlattevőazonosító;
        $this->vezetéknév = $vnév;
        $this->keresztnév = $knév;
        $this->cím = $cím;
        $this->telefon = $telefon;
    }

    function __toString() {
        $kimenet = "<h2>Ajánlattevő száma: $this->ajánlattevőazonosító</h2>\n" .
                  "<h2>$this->vezetéknév, $this->keresztnév</h2>\n" .
                  "<h2>$this->cím</h2>\n" .
                  "<h2>$this->telefon</h2>\n";
        return $kimenet;
    }

    function ajánlattevőMentése() {
        $adatb = new mysqli("localhost", "ás_felhasználó", "ArveresSeged", "árverés");
        $lekérdezés = "INSERT INTO ajánlattevők VALUES (?, ?, ?, ?, ?)";
        $ut = $adatb->prepare($lekérdezés);
        $ut->bind_param("issss", $this->ajánlattevőazonosító, $this->vezetéknév,
                          $this->keresztnév, $this->cím, $this->telefon);
        $eredmény = $ut->execute();
        $adatb->close();
        return $eredmény;
    }

    function ajánlattevőFrissítése() {
        $adatb = new mysqli("localhost", "ás_felhasználó", "ArveresSeged", "árverés");
        $lekérdezés = "UPDATE ajánlattevők SET ajánlattevőazonosító = ?, vezetéknév = ?, " .
                 "keresztnév = ?, cím = ?, telefon = ? " .
                 "WHERE ajánlattevőazonosító = $this->ajánlattevőazonosító";
        $ut = $adatb->prepare($lekérdezés);
        $ut->bind_param("issss", $this->ajánlattevőazonosító, $this->vezetéknév,
                          $this->keresztnév, $this->cím, $this->telefon);
        $eredmény = $ut->execute();
        $adatb->close();
        return $eredmény;
    }

    function ajánlattevőEltávolítása() {
        $adatb = new mysqli("localhost", "ás_felhasználó", "ArveresSeged", "árverés");
        $lekérdezés = "DELETE FROM ajánlattevők WHERE ajánlattevőazonosító = $this->ajánlattevőazonosító";
        $eredmény = $adatb->query($lekérdezés);
        $adatb->close();
        return $eredmény;
    }

    static function ajánlattevőkLekérése() {
        $adatb = new mysqli("localhost", "ás_felhasználó", "ArveresSeged", "árverés");
        $lekérdezés = "SELECT * FROM ajánlattevők";
        $eredmény = $adatb->query($lekérdezés);
        if (mysqli_num_rows($eredmény) > 0) {
            $ajánlattevők = array();
            while($sor = $eredmény->fetch_array(MYSQLI_ASSOC)) {
                $ajánlattevő = new Ajánlattevő($sor['ajánlattevőazonosító'],$sor['vezetéknév'],
                          $sor['keresztnév'],$sor['cím'],$sor['telefon']);
                array_push($ajánlattevők, $ajánlattevő);
                unset($ajánlattevő);
            }
            $adatb->close();
            return $ajánlattevők;
        } else {
            $adatb->close();
            return NULL;
        }
    }

    static function ajánlattevőKeresése($ajánlattevőazonosító) {
        $adatb = new mysqli("localhost", "ás_felhasználó", "ArveresSeged", "árverés");
        $lekérdezés = "SELECT * FROM ajánlattevők WHERE ajánlattevőazonosító = $ajánlattevőazonosító";
        $eredmény = $adatb->query($lekérdezés);
        $sor = $eredmény->fetch_array(MYSQLI_ASSOC);
        if ($sor) {
            $ajánlattevő = new Ajánlattevő($sor['ajánlattevőazonosító'],$sor['vezetéknév'],
                      $sor['keresztnév'],$sor['cím'],$sor['telefon']);
            $adatb->close();
            return $ajánlattevő;
        } else {
            $adatb->close();
            return NULL;
        }
    }
	
	static function ajánlattevőkSzámánakLekérése() {
		$adatb = new mysqli("localhost", "ás_felhasználó", "ArveresSeged", "árverés");
		$lekérdezés = "SELECT count(ajánlattevőazonosító) FROM ajánlattevők";
		$eredmény = $adatb->query($lekérdezés);
		$sor = $eredmény->fetch_array();
		if ($sor) {
			return $sor[0];
		} else {
			return NULL;
		}
	}

}
?>