<?php
$dok = new DOMDocument("1.0");

$autókereskedés = $dok->createElement("autókereskedés");
$autókereskedés = $dok->appendChild($autókereskedés);
$autó1 = $dok->createElement("autó");
$autó1 = $autókereskedés->appendChild($autó1);
$márka1 = $dok->createAttribute("márka");
$márka1->value = "Renault";
$autó1->appendChild($márka1);
$modell1 = $dok->createElement("modell", "Clio");
$modell1 = $autó1->appendChild($modell1);
$modell2 = $dok->createElement("modell", "Mégane");
$modell2 = $autó1->appendChild($modell2);

$autó2 = $dok->createElement("autó");
$autó2 = $autókereskedés->appendChild($autó2);
$márka2 = $dok->createAttribute("márka");
$márka2->value = "Ford";
$autó2->appendChild($márka2);
$modell3 = $dok->createElement("modell", "Mondeo");
$modell3 = $autó2->appendChild($modell3);

$kimenet = $dok->saveXML();
header("Content-type: application/xml");
echo $kimenet;
?>