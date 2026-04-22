<?php
class Tétel {
    public $tételazonosító;
    public $név;
    public $leírás;
    public $viszonteladóiár;
    public $nyertesajánlattevő;
    public $nyertesár;

    function __construct($tételazonosító, $név, $leírás, $viszonteladóiár,
                         $nyertesajánlattevő, $nyertesár) {
        $this->tételazonosító = $tételazonosító;
        $this->név = $név;
        $this->leírás = $leírás;
        $this->viszonteladóiár = $viszonteladóiár;
        $this->nyertesajánlattevő = $nyertesajánlattevő;
        $this->nyertesár = $nyertesár;
    }

    function __toString() {
        $kimenet = "<h2>Tétel : $this->tételazonosító</h2>" .
                  "<h2>Név: $this->név</h2>\n";
                  "<h2>Leírás: $this->leírás</h2>\n";
                  "<h2>Viszonteladói ár: $this->viszonteladóiár</h2>\n";
                  "<h2>Nyertes ajánlat: $this->nyertesajánlattevő $this->nyertesár áron</h2>\n";
        return $kimenet;
    }

    function tételMentése() {
        $adatb = new mysqli("localhost","ás_felhasználó","ArveresSeged","árverés");
        $lekérdezés = "INSERT INTO tételek VALUES (?, ?, ?, ?, ?, ?)";
        $ut = $adatb->prepare($lekérdezés);
        $ut->bind_param("issdsd", $this->tételazonosító, $this->név,
                           $this->leírás, $this->viszonteladóiár,
                           $this->nyertesajánlattevő, $this->nyertesár);
        $eredmény = $ut->execute();
        $adatb->close();
        return $eredmény;
    }

    function tételFrissítése() {
        $adatb = new mysqli("localhost","ás_felhasználó","ArveresSeged","árverés");
        $lekérdezés = "UPDATE tételek SET név= ?, leírás = ?, viszonteladóiár = ?, " .
                 "nyertesajánlattevő = ?, nyertesár = ? WHERE tételazonosító = $this->tételazonosító";
        $ut = $adatb->prepare($lekérdezés);
        $ut->bind_param("ssdsd", $this->név, $this->leírás,
                      $this->viszonteladóiár, $this->nyertesajánlattevő, $this->nyertesár);
        $eredmény = $ut->execute();
        $adatb->close();
        return $eredmény;
    }

    function tételEltávolítása() {
        $adatb = new mysqli("localhost", "ás_felhasználó", "ArveresSeged", "árverés");
        $lekérdezés = "DELETE FROM tételek WHERE tételazonosító = $this->tételazonosító";
        $eredmény = $adatb->query($lekérdezés);
        $adatb->close();
        return $eredmény;
    }

    static function tételekLekérése() {
        $adatb = new mysqli("localhost", "ás_felhasználó", "ArveresSeged", "árverés");
        $lekérdezés = "SELECT * FROM tételek";
        $eredmény = $adatb->query($lekérdezés);
        if (mysqli_num_rows($eredmény) > 0) {
            $tételek = array();
            while($sor = $eredmény->fetch_array(MYSQLI_ASSOC)) {
                $tétel = new Tétel($sor['tételazonosító'], $sor['név'],
                                 $sor['leírás'], $sor['viszonteladóiár'],
                                 $sor['nyertesajánlattevő'], $sor['nyertesár']);
                array_push($tételek, $tétel);
            }
            $adatb->close();
            return $tételek;
        } else {
            $adatb->close();
            return NULL;
        }
    }

    static function tételekLekéréseAjánlattevőSzerint($ajánlattevőazonosító) {
        $adatb = new mysqli("localhost", "ás_felhasználó", "ArveresSeged", "árverés");
        $lekérdezés = "SELECT * FROM tételek WHERE nyertesajánlattevő = $ajánlattevőazonosító";
        $eredmény = $adatb->query($lekérdezés);
        if (mysqli_num_rows($eredmény) > 0) {
            $tételek = array();
            while($sor = $eredmény->fetch_array(MYSQLI_ASSOC)) {
                $tétel = new Tétel($sor['tételazonosító'], $sor['név'],
                                 $sor['leírás'], $sor['viszonteladóiár'],
                                 $sor['nyertesajánlattevő'], $sor['nyertesár']);
                array_push($tételek, $tétel);
            }
            $adatb->close();
            return $tételek;
        } else {
            $adatb->close();
            return NULL;
        }
    }

    static function tételKeresése($tételazonosító) {
        $adatb = new mysqli("localhost", "ás_felhasználó", "ArveresSeged", "árverés");
        $lekérdezés = "SELECT * FROM tételek WHERE tételazonosító = $tételazonosító";
        $eredmény = $adatb->query($lekérdezés);
        $sor = $eredmény->fetch_array(MYSQLI_ASSOC);
        if ($sor) {
            $tétel = new Tétel($sor['tételazonosító'], $sor['név'], $sor['leírás'],
            $sor['viszonteladóiár'], $sor['nyertesajánlattevő'], $sor['nyertesár']);
            $adatb->close();
            return $tétel;
        } else {
            $adatb->close();
            return NULL;
        }
    }
	
	static function tételekSzámánakLekérése() {
		$adatb = new mysqli("localhost", "ás_felhasználó", "ArveresSeged", "árverés");
		$lekérdezés = "SELECT count(tételazonosító) FROM tételek";
		$eredmény = $adatb->query($lekérdezés);
		$sor = $eredmény->fetch_array();
		if ($sor) {
			return $sor[0];
		} else {
			return NULL;
		}
	}

	static function összesítettÁrakLekérése() {
		$adatb = new mysqli("localhost", "ás_felhasználó", "ArveresSeged", "árverés");
		$lekérdezés = "SELECT sum(viszonteladóiár) FROM tételek";
		$eredmény = $adatb->query($lekérdezés);
		$sor = $eredmény->fetch_array();
		if ($sor) {
			return $sor[0];
		} else {
			return NULL;
		}
	}

	static function összesítettAjánlatokLekérése() {
		$adatb = new mysqli("localhost", "ás_felhasználó", "ArveresSeged", "árverés");
		$lekérdezés = "SELECT sum(nyertesár) FROM tételek";
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