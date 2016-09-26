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
    BigNumber getK();
    String toString();
  private:
    void init();
    BigNumber parseString(String in);
    BigNumber b;
    BigNumber p;
    BigNumber g;
    BigNumber A;
    BigNumber B;
    BigNumber K;
};

#endif
