#include <iostream>

using namespace std;

bool isDivisible(const long & num)
{
   for(int i = 20; i > 1; --i)
   {
      if(num % i != 0)
         return false;
   }
   return true;
}

int main()
{
   long num = 2;

   while(!isDivisible(num))
   {
      num++;
   }
   cout<< num << endl;
}
