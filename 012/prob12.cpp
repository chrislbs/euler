#include <iostream>
#include <vector>
#include <cmath>
#include "utility.h"
#include <iomanip>

using std::vector;
using std::cout;
using std::setw;
using std::endl;
using utility::primeSieve;

int getDivisors(int num)
{
   int sq = static_cast<int>(sqrt(static_cast<double>(num)));

   int div = 0;
   for(int i = 1; i <= sq; i++)
   {
      if(num % i == 0)
      {
         if(num / i != i)
            div += 2;
         else
            div++;
      }
   }
   return div;
}

int getNextTriNum()
{
   static int curTri = 0;
   static int count = 1;
   curTri += count++;
   
   return curTri;
}

int main()
{
   int tri = getNextTriNum();
   while(getDivisors(tri) < 500)
      tri = getNextTriNum();

   cout<< tri << endl;

   return 0;
}
