#include <iostream>

using namespace std;

int main()
{
   unsigned long sumsq = 0, sqsum = 0;
   
   for(int i = 1; i <= 100; i++)
   {
      sumsq += i * i;
      sqsum += i;
   }
   sqsum *= sqsum;
   
   cout<< sqsum - sumsq << endl;
   
   return 0;
}
