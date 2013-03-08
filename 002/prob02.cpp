#include <iostream>

int addEvenFib(int a, int b)
{
   if(b > 4000000)
      return 0;
   return b % 2 == 0 ? b + addEvenFib(b, a + b) : addEvenFib(b, a + b);
}

int main()
{
   std::cout<< addEvenFib(1, 1);
}

