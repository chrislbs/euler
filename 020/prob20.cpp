#include <iostream>
#include "BigIntegerLibrary.hh"

using namespace std;

BigInteger factorial(int n)
{
   return n == 1 ? 1 : factorial(n - 1) * n;
}

int main()
{
   const int N = 100;
   BigInteger val = factorial(N);

   BigInteger sum = 0;
   while(val > 0)
   {
      sum += val % 10;
      val /= 10;
   }

   cout<< sum << endl;

   return 0;
}
