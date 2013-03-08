#include <iostream>
#include <map>

using std::cout;
using std::endl;

unsigned long getSeqCount(unsigned long start)
{
   // start number, sequence count
   static std::map<unsigned long, unsigned long> seqMap;

   unsigned long count = 1, init = start;
   while(init > 1)
   {
      count++;
      if(seqMap.find(init) != seqMap.end())
      {
         count += seqMap[init];
         break;
      }
      if( init % 2 == 0)
         init /= 2;
      else
         init = 3 * init + 1;
   }
   seqMap[start] = count;

   return count;
}

int main()
{
   std::pair<unsigned long, unsigned long> largest(0, 0);

   int cnt;
   for(int i = 2; i < 1000000; i++)
   {
      cnt = getSeqCount(i);
      if(cnt > largest.second)
      {
         largest.first = i;
         largest.second = cnt;
      }
   }

   cout<< largest.first << endl;
}
