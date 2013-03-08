#include <iostream>

int main()
{
   int i = 0, sum = 0;
   while(++i < 1000)
   {
      if( i % 3 == 0)
      {
         sum += i;
         continue;
      }
      if( i % 5 == 0)
      {
         sum += i;
         continue;
      }
   }
   std::cout<< sum << std::endl;

   return 0;
}
