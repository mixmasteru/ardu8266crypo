<?php
/**
 * Class for Diffie-Hellman Key Exchange
 *
 * @see https://de.wikipedia.org/wiki/Diffie-Hellman-Schlüsselaustausch
 */
class DiffieHellman
{
  const MIN_RAND = 1000;
  const MAX_RAND = 10000;

  protected $p;
  protected $g;
  protected $a;
  protected $A;

  //exchange key
  protected $B;

  //result key
  protected $K;

  function __construct()
  {
    $this->init();
  }

  protected function init()
  {
    //Mersenne-Primzahl 15 	1279 	386 	1952 	Robinson
    $this->p = bcpow('2', '1279');
    $this->p = bcsub($this->p,1);

    $this->g = bcpow('2', '111');

    //random key
    $this->a = rand(self::MIN_RAND,self::MAX_RAND);
    $this->A = bcmod(bcpow($this->g,$this->a),$this->p);
  }

  public function exchange($B)
  {
    $this->B = trim($B);
    $this->K = bcmod(bcpow($this->B,$this->a),$this->p);
  }

  public function toString()
  {
    $return  = "a: ".$this->a."\n";
    $return .= "g: ".$this->g."\n";
    $return .= "p: ".$this->p."\n";
    $return .= "A: ".$this->A."\n";
    $return .= "B: ".$this->B."\n";
    $return .= "K: ".$this->K;

    return $return;
  }

  public function getA()
  {
    return $this->A;
  }
}
