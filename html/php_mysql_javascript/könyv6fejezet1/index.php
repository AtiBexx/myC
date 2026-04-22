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
</aside>
</section>
<footer>
<?php include("lábléc.inc.php"); ?>
</footer>
</body>
</html>