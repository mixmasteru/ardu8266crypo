/*
  DiffieHellman.cpp - Library for Diffie-Hellman Keyexchange
*/

#include "DiffieHellman.h"


DiffieHellman::DiffieHellman() : b(0), p(0), g(0), A(0), B(0), K(0)
{
  BigNumber::begin ();
  this->init();
}

void DiffieHellman::init()
{
  BigNumber base = 2;
  this->p = base.pow(1279);
  this->p--;
  this->g = base.pow(111);
  this->b = random(1000,10000);
  this->B = this->g.powMod(this->b, this->p);
}

BigNumber DiffieHellman::exchange(BigNumber A)
{
  this->A = A;
  this->K = this->A.powMod(this->b, this->p);
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
  return this->B;
}

BigNumber DiffieHellman::getK()
{
  return this->K;
}
