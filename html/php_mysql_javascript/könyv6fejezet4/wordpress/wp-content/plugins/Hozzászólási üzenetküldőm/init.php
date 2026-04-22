<?php
/*
Name: Hozzászólási üzenetküldőm
Description: E-mailt ír nekem, amikor valaki hozzászólást ír
*/
function hozzászólási_üzenetküldőm($hozzászólás_azonosító) {
    $címem = "cimem@localhost.hu";
    $üzenet = "Az imént tették közzé a(z) $hozzászólás_azonosító hozzászólást a weboldalamon";
    mail($címem, "Hozzászólás a weboldalon", $üzenet);
    return $hozzászólás_azonosító;
}
add_action('comment_post', 'hozzászólási_üzenetküldőm');
?>