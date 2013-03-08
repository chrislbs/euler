#include <iostream>
#include <string.h>
#include <algorithm>

// it's including permuations that have already been counted
// i.e. 0123: 1023 is perm 7, but with the remaining 5 it is include 1023 as a perm.

using namespace std;

int factorial(int n)
{
   return n == 1 ? 1 : n * factorial(n - 1);
}

// assumes sorted 
int mutate(char * start, char * end, int numperm)
{
   int len = end - start;
   int fact = factorial(len);
   if(fact < numperm)
      return 0;
   else if(fact == numperm)
   {
      reverse(start, end);
      return 0;
   }

   int offset = 0;
   while(fact > numperm)
      fact /= len - offset++;

   start += offset - 1;

   int idx = 0; 
   while(numperm >= fact)
   {
      numperm -= fact;
      idx++;
   }
   if(numperm == 0)
   {
      swap(*start, *(start + --idx));
      reverse(start + idx, end);
   }
   else
   {
      swap(*start, *(start +idx));
      sort(start + 1, end);
   }
   cout<< start << "\t" << numperm << endl;

   return numperm <= 1 ? 0 : mutate(start, end, numperm);
}

int main()
{
   char lexi[] = "0123456789";
   int perm = 1000000;
   //char lexi[] = "0123";
   //int perm = 12;

   int len = strlen(lexi);

   mutate(lexi, lexi + len, perm);
   //cout<< mutate(lexi, lexi + len, perm) << "\t" << lexi << endl;
   cout<< lexi << endl;

   /*int offset = 0, factor = 1;
   for(int i = 0; i < strlen(lexi); i++)
   {
      factor *= i + 1;
      if(factor < perm) 
         offset = i;
      else
      {
         factor /= i + 1;
         break;
      }
   }

   while(*/

   return 0;
}
