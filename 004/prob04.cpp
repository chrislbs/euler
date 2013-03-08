#include <iostream>
#include <stdio.h>
#include <sstream>
#include <string.h>
#include <algorithm>

using namespace std;

bool isPalindrome(string str)
{
   int hlen = str.size() / 2;
   string revStr = str.substr(hlen + str.size() % 2, hlen);

   reverse(revStr.begin(), revStr.end());
   if(str.substr(0, hlen) == revStr)
      return true;
   else
      return false;
}

int main()
{
   unsigned long num;
   unsigned long largest = 0;

   for(int i = 100; i < 1000; i++)
   {
      for(int j = i; j < 1000; j++)
      {
         num = i * j;
         if(num < largest)
            continue;
         stringstream numStr;
         numStr << num;
         if(isPalindrome(numStr.str()))
            largest = num;
      }
   }
   cout<< largest << endl;
}
