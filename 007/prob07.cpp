#include <iostream>
#include <vector>

#define NUMPRIMES 10001

using namespace std;

int main()
{
   vector<int> primes;
   vector<int>::iterator it;
   int num = 3;
   
   primes.reserve(NUMPRIMES);
   primes.push_back(2);
   while(primes.size() < NUMPRIMES)
   {
      bool isPrime = true;
      int count = 0;
      for(it = primes.begin(); it < primes.end(); it++)
      {
         if( num % *it == 0)
         {
            isPrime = false;
            break;
         }
      }
      if(isPrime)
         primes.push_back(num);
      num += 2;
   }
   cout<< *(primes.end() - 1) << endl;
}
