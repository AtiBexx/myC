<?php
session_start();
include("ajánlattevő.php");
include("tétel.php");
?>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>ÁrverésSegéd</title>
<link rel="stylesheet" type="text/css" href="ás_stílusok.css">
<script language="javascript" type="text/javascript">
function valósIdejűAdatokLekérése() {
    // a DOM-objektumok lekérése a tartalom elhelyezéséhez
    var domajánlattevők = document.getElementById("ajánlattevőszám");
    var domtételek = document.getElementById("tételszám");
    var domtételösszeg = document.getElementById("tételösszeg");
    var domajánlatösszeg = document.getElementById("ajánlatösszeg");
    // a GET kérés elküldése az adatok lekéréséhez
    var kérés = new XMLHttpRequest();
    kérés.open("GET", "valósidejű.php", true);
    kérés.onreadystatechange = function() {
        if (kérés.readyState == 4 && kérés.status == 200) {
            // az XML-dokumentum elemzése az egyes adatelemek lekéréséhez
            var xmldok = kérés.responseXML;

            var xmlajánlattevők = xmldok.getElementsByTagName("ajánlattevők")[0];
            var ajánlattevők = xmlajánlattevők.childNodes[0].nodeValue;

            var xmltételek = xmldok.getElementsByTagName("tételek")[0];
            var tételek = xmltételek.childNodes[0].nodeValue;

            var xmltételösszeg = xmldok.getElementsByTagName("tételösszeg")[0];
            var tételösszeg = xmltételösszeg.childNodes[0].nodeValue;

            var xmlajánlatösszeg = xmldok.getElementsByTagName("ajánlatösszeg")[0];
            var ajánlatösszeg = xmlajánlatösszeg.childNodes[0].nodeValue;

            domajánlattevők.innerHTML = ajánlattevők;
            domtételek.innerHTML = tételek;
            domtételösszeg.innerHTML = tételösszeg;
            domajánlatösszeg.innerHTML = ajánlatösszeg;
        }
    };
    kérés.send();
}
</script>
</head>
<body>
<header>
<?php include("fejléc.inc.php"); ?>
</header>
<section id="tároló">
<nav>
<?php include("nav.inc.php"); ?>
</nav>
<main>
<?php
if (isset($_REQUEST['tartalom'])) {
    include($_REQUEST['tartalom'] . ".inc.php");
} else {
    include("főoldal.inc.php");
}
?>
</main>
<aside>
<?php include("oldalsáv.inc.php"); ?>
<script language="javascript" type="text/javascript">
valósIdejűAdatokLekérése();
setInterval(valósIdejűAdatokLekérése, 5000);
</script>
</aside>
</section>
<footer>
<?php include("lábléc.inc.php"); ?>
</footer>
</body>
</html>