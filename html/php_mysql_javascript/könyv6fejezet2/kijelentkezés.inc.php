<?php
if (isset($_SESSION['bejelentkezés']))
{
   unset($_SESSION['bejelentkezés']);
}
header("Location: index.php");
?>