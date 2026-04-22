<?php
session_start();
?>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>Kosárteszt</title>
</head>
<body>
<h1>Elérhető árucikkek</h1>
<form action="kosárteszt.php" method="post">
<table>
<tr><th>Árucikk</th><th>Mennyiség</th></tr>
<tr><td>Alma</td><td><input type="text" name="alma" size="2"></td></tr>
<tr><td>Banán</td><td><input type="text" name="banán" size="2"></td></tr>
</table>
<input type="submit" value="Kattints ide a kosárba rakáshoz">
</form>
<br>
<?php
    if (isset($_POST['alma'])) {
        if (is_numeric($_POST['alma'])) {
            $_SESSION['kosár']['alma'] = $_POST['alma'];
        } elseif ($_POST['alma'] == "Eltávolítás") {
            unset($_SESSION['kosár']['alma']);
        }
    }

    if (isset($_POST['banán'])) {
        if (is_numeric($_POST['banán'])) {
            $_SESSION['kosár']['banán'] = $_POST['banán'];
        } elseif ($_POST['banán'] == "Eltávolítás") {
            unset($_SESSION['kosár']['banán']);
        }
    }
?>
<fieldset style="width:300px">
<legend>A kosarad</legend>
<?php
    if (!isset($_SESSION['kosár'])) {
        $_SESSION['kosár'] = array();
        echo "A kosarad üres\n";
    } else {
        echo "<form action=\"kosárteszt.php\" method=\"post\">\n";
        echo "<table>\n";
        echo "<tr><th>Árucikk</th><th>Mennyiség</th><th></th></tr>\n";
        foreach ($_SESSION['kosár'] as $kulcs => $érték) {
            echo "<tr><td>$kulcs</td><td>$érték</td>\n";
            echo "<td><input type=\"submit\" name=\"$kulcs\" value=\"Eltávolítás\"></td></tr>\n";
        }
        echo "</table>\n";
        echo "</form>\n";
    }
?>
</fieldset>
</body>
</html>