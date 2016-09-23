/*
  diffhell.h - Library for Diffie-Hellman Keyexchange
*/
#ifndef DiffieHellman_h
#define DiffieHellman_h

#include "BigNumber.h"

class DiffieHellman
{
  public:
    DiffieHellman();
    BigNumber exchange(BigNumber A);
    BigNumber exchange(String strA);
    BigNumber getB();
    String toString();
  private:
    void init();
    BigNumber parseString(String in);
    int _b;
    BigNumber _p;
    BigNumber _g;
    BigNumber _A;
    BigNumber B;
    BigNumber _K;
};

#endif
