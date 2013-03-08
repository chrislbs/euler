#include <iostream>
#include <vector>
#include "utility.h"

using namespace std;
using utility::primeSieve;

#ifndef ULONG
#define ULONG unsigned long
#endif

int main()
{
   vector<ULONG> primes;
   ULONG totPrimes = 2000000;
   ULONG sum = 0;

   primeSieve(totPrimes, primes);

   for(vector<ULONG>::iterator it = primes.begin(); it < primes.end(); it++)
   {
      sum += (*it);
   }
   cout<< sum << endl;

   return 0;
}
