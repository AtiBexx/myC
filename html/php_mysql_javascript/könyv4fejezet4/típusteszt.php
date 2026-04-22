<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>Adattípusteszt</title>
<style>
    .figyelmeztetés {
        color:red;
    }
</style>
</head>
<body>
<h1>Az űrlap eredményei:</h1>
<?php
$név = htmlspecialchars($_POST['név']);
$email = htmlspecialchars($_POST['email']);
$kor = htmlspecialchars($_POST['kor']);

echo "<p>Név: $név</p>\n";
if (filter_var($email, FILTER_VALIDATE_EMAIL)) {
    echo "<p>E-mail: $email</p>\n";
} else {
    echo "<p class='figyelmeztetés'>Adj meg egy érvényes
            e-mail-címet</p>\n";
}
if (is_numeric($kor)) {
   echo "<p>Kor: $kor</p>\n";
} else {
   echo "<p class='figyelmeztetés'>Adj meg egy érvényes
           kort</p>\n";
}
?>
<br>
<a href="típusteszt.html">Vissza az űrlaphoz</a>
</body>
</html>