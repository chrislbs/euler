#include <iostream>
#include <limits.h>
#include <math.h>
#include <stdio.h>
using namespace std;

#define MAX_PERIM 1000000000

int main()
{
   unsigned long sum = 0;
   unsigned long s = 2;
//   long double h;
   long double a;

   while(3 * s - 1 <= MAX_PERIM)
   {
//      h = sqrt(s * s -  (s + 1) * (s + 1) * .25);
//      a = .5 * (s + 1) * h;
      a = sqrt(3 * s * s - 2 * s - 1) * ( s + 1 ) / 4;
      if(a - (unsigned long) a  == 0)
      {
         sum += (unsigned long)3 * s + 1;
//         printf("h = %20.10Lf a = %20.10Lf s = %20.10Lf   s+1\n", h, a, s);
      }
//      h = sqrt(s * s - (s - 1) * (s - 1) * .25);
//      a = .5 * (s - 1) * h;
      a = sqrt(3 * s * s + 2 * s - 1) * ( s - 1 ) / 4; 
      if(a - (unsigned long) a  == 0)
      {
         sum += (unsigned long)3 * s - 1;
//         printf("h = %20.10Lf a = %20.10Lf s = %20.10Lf   s-1\n", h, a, s);
      }
      s++;
   }
   cout<< endl << endl << sum << endl;
}
