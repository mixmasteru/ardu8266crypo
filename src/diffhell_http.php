<?php
include_once("diffhell.php");

if(!empty($_GET["B"]))
{
  $dh = new DiffieHellman();
  $B = $_GET["B"];
  $dh->exchange($B);
  echo $dh->toString();
}
