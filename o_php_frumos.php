<?php

$titlu = "O, php frumos";
$continut = "Cu ... variabila tot verde";

$titluri = array();
$titluri[] = "Mos PHP";
$titluri[] = "PHP cu paru cret";
$titluri[] = "Pe langa PHP-u fara sot";
$titluri[] = "Somnoroase variabile";
$titluri[] = "Oda pentru Aluxian";

echo $titluri[rand(0, 4)];
echo "<br>".$continut;

?>