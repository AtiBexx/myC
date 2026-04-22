<?php
/*
Plugin Name: ÁrverésSegéd
Description: Valós idejű adatokat kér le az ÁrverésSegéd alkalmazásból
*/

class ÁrverésSegéd extends WP_Widget {
    function ÁrverésSegéd() {
        parent::WP_Widget(false, "ÁrverésSegéd");
    }

    function widget($args, $instance) {
        $adatb = new mysqli("localhost", "ás_felhasználó", "ÁrverésSegéd", "árverés");
        $lekérdezés = "SELECT count(ajánlattevőazonosító) FROM ajánlattevők";
        $eredmény = $adatb->query($lekérdezés);
        $sor = $eredmény->fetch_array();
        $ajánlattevők = $sor[0];

        $lekérdezés = "SELECT count(tételazonosító) FROM tételek";
        $eredmény = $adatb->query($lekérdezés);
        $sor = $eredmény->fetch_array();
        $tételek = $sor[0];

        $lekérdezés = "SELECT sum(viszonteladóiár) FROM tételek";
        $eredmény = $adatb->query($lekérdezés);
        $sor = $eredmény->fetch_array();
        $összár = $sor[0];

        echo "<h2>Az árverés összesített adatai</h2><hr>\n";
        echo "Regisztrált ajánlattevők: $ajánlattevők<br>\n";
        echo "Tételek összesen: $tételek<br>\n";
        echo "A tételek viszonteladási értéke: $összár Ft<br>\n";
        echo "<hr><br>\n";
    }
}

function ÁrverésSegéd_regisztrálása() {
    register_widget('ÁrverésSegéd');
}

add_action('widgets_init', 'ÁrverésSegéd_regisztrálása');
?>