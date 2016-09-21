#include <Arduino.h>
// BigNumber test: powers
#include "BigNumber.h"

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

// function to display a big number and free it afterwards
void printBignum (BigNumber & n)
{
  char * s = n.toString ();
  Serial.println (s);
  free (s);
}  // end of printBignum

BigNumber parseString(String in)
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

void setupDiffi ()
{
  Serial.begin (9600);
  Serial.setTimeout(1000000);
  Serial.println ("start");
  // reserve 200 bytes for the inputString:
  inputString.reserve(400);
  BigNumber::begin ();  // initialize library

}  // end of setup

void loopDiffi ()
{
  delay(3000);
  BigNumber base = 2;
  BigNumber p = base.pow(1279);
  p--;
  BigNumber g = base.pow(111);
  int b = random(1000,10000);
  BigNumber B = g.powMod(b, p);

  Serial.print("g: ");
  printBignum (g);
  Serial.print("p: ");
  printBignum (p);
  Serial.print("B: ");
  printBignum (B);

  while (true) {
    // get the new byte:
    if(Serial.available())
    {
      String str = Serial.readStringUntil('\n');
      BigNumber A = parseString(str);
      Serial.println();
      Serial.print("A: ");
      printBignum (A);
      BigNumber K = A.powMod(b, p);
      Serial.print("K: ");
      printBignum (K);
    }
    //delay(1000);
  }
}//loop
