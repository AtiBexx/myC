<?php
include("ajánlattevő.php");
include("tétel.php");

$ajánlattevők = Ajánlattevő::ajánlattevőkSzámánakLekérése();
$tételek = Tétel::tételekSzámánakLekérése();
$tételösszeg = Tétel::összesítettÁrakLekérése();
$ajánlatösszeg = Tétel::összesítettAjánlatokLekérése();

$dok = new DOMDocument("1.0");
$árverés = $dok->createElement("árverés");
$árverés = $dok->appendChild($árverés);

$ajánlattevők = $dok->createElement("ajánlattevők", $ajánlattevők);
$ajánlattevők = $árverés->appendChild($ajánlattevők);

$tételek = $dok->createElement("tételek", $tételek);
$tételek = $árverés->appendChild($tételek);
$tételösszeg = $dok->createElement("tételösszeg", $tételösszeg);
$tételösszeg = $árverés->appendChild($tételösszeg);
$ajánlatösszeg = $dok->createElement("ajánlatösszeg", $ajánlatösszeg);
$ajánlatösszeg = $árverés->appendChild($ajánlatösszeg);
$kimenet = $dok->saveXML();

header("Content-type: application/xml");
echo $kimenet;
?>