/*
  DiffieHellman.cpp - Library for Diffie-Hellman Keyexchange
*/

#include "DiffieHellman.h"

DiffieHellman::DiffieHellman()
{
  this->init();
}

void DiffieHellman::init()
{
  BigNumber base = 2;
  _p = base.pow(1279);
  _p--;
  _g = base.pow(111);
  _b = random(1000,10000);
  B = this->_g.powMod(_b, _p);
}

BigNumber DiffieHellman::exchange(BigNumber A)
{
  _A = A;
  _K = this->_A.powMod(_b, _p);
  return B;
}

BigNumber DiffieHellman::exchange(String strA)
{
  BigNumber A = this->parseString(strA);
  return this->exchange(A);
}

BigNumber DiffieHellman::parseString(String in)
{
  BigNumber out = 0;
  BigNumber ten = 10;

  for(int i = 1;i<in.length();i++)
  {
      BigNumber bi = in.substring(i-1,i).toInt();
      out += bi * ten.pow(in.length()-i-1);
      //Serial.println(str.substring(i-1,i).toInt());
  }

  return out;
}

String DiffieHellman::toString()
{
  String out = "g: ...";

  return out;
}

BigNumber DiffieHellman::getB()
{
  return B;
}
