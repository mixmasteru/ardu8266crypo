<?php
const MIN_RAND = 1000;
const MAX_RAND = 10000;
//https://de.wikipedia.org/wiki/Diffie-Hellman-Schlüsselaustausch

//Mersenne-Primzahl 15 	1279 	386 	1952 	Robinson
$p = bcpow('2', '1279');
$p = bcsub($p,1);
$g = bcpow('2', '111');

//random key
$a = rand(MIN_RAND,MAX_RAND);
$A = bcmod(bcpow($g,$a),$p);

echo "a: ".$a."\n";
echo "g: ".$g."\n";
echo "p: ".$p."\n";
echo "A: ".$A."\n";
$B = readline("B:");
$K = bcmod(bcpow($B,$a),$p);
echo "K: ".$K."\n";
