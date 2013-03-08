#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <queue>

using namespace std;

string filename = "prob08.txt";

int main()
{
   fstream file(filename.c_str(), fstream::in | fstream::out);
   int length = file.seekg(0, fstream::end).tellg();
   file.seekg(0, fstream::beg);

   char * buffer = new char[length];
   file.read(buffer, length);
   string str(buffer);
   delete [] buffer;
   file.close();
   
   size_t index = str.find('\n');
   while(index != string::npos)
   {
      str.erase(index, 1);
      index = str.find('\n');
   }

   string::iterator it;
   queue<char> nums;
   int largest = 0, current = 1;
   for(it = str.begin(); it < str.end(); it++)
//   for(it = str.begin(); it < str.begin() + 10; it++)
   {
      int val = (*it) - 48;
      if(val == 0)
      {
         while(!nums.empty())
         {
            nums.pop();
         }
         current = 1;
         continue;
      }
      current *= val;
      nums.push(val);
      if(nums.size() < 5)
      {
         continue;
      }
      else
      {
         int n = nums.front();
         if(current > largest)
         {
            largest = current;
         }
         current /= n; 
         nums.pop();
      }
   }
   cout<< largest;

   return 0;
}
