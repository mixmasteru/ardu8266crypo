<?php
include_once("diffhell.php");

if(!empty($_GET["B"]))
{
  $dh = new DiffieHellman();
  $B = $_GET["B"];
  $dh->exchange($B);

  ob_start();
  var_dump($dh->toString());
  error_log(ob_get_clean(), 4);

  header('Content-Type: text/plain');
  echo $dh->getA().PHP_EOL;
}
