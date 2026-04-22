<?php
$márka = $_GET['márka'];
switch ($márka)
{
    case "volkswagen":
        echo "Polo,Golf,Passat";
        break;
    case "toyota":
        echo "Yaris,Corolla,Rav4";
        break;
    case "renault":
        echo "Clio,Mégane,Captur";
        break;
    case "ford":
        echo "Fiesta,Fusion,Mondeo";
}
?>