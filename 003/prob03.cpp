#include <iostream>
#include <math.h>

using std::cout;

int main()
{
   unsigned long max = 600851475143;
   unsigned long maxPrime = 0;

   int i = 3;
   
   while(max != 1)
   {
      if(max % i == 0)
      {
         maxPrime = i;
         do
         {
            max /= i;
         }while(max % i == 0);
      }
      i += 2;
   }

   cout<< maxPrime << std::endl;
   return 0;
}
