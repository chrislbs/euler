#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <math.h>

typedef std::set<unsigned int> prime_set;
typedef prime_set::iterator prime_iter;
typedef prime_set::const_iterator const_prime_iter;
typedef std::pair<prime_iter, bool> prime_insert;
typedef std::map<unsigned int, unsigned int> factor_map;

void prime_sieve(unsigned int num_primes, std::set<unsigned int>& prime_cont)
{
   std::vector<bool> primes(num_primes, true);

   prime_cont.insert(2);

   for(unsigned int i = *(prime_cont.begin()); i * i <= num_primes; i++)
   {
      if(primes[i - 1] == false)
         continue;
      
      for(unsigned int j = i * i; j <= num_primes; j += i)
         primes[j - 1] = false;
   }

   for(unsigned int i = *(prime_cont.rend()); i <= num_primes; i++)
   {
      if(primes[i - 1])
         prime_cont.insert(i);
   }
       
}

void get_factors(unsigned int val, const prime_set& primes, factor_map& factors)
{
   for(const_prime_iter it = primes.begin(); it != primes.end(); it++)
   {
      factors[*it] = 0;
      while(val % *it == 0)
      {
         factors[*it]++;
         val /= *it;
      }
      if(val == 1)
         break;
   }
}

int main()
{
   long num = 2;

   std::set<unsigned int> primes;

   prime_sieve(20, primes);

   factor_map greatest;

   for(unsigned int i = 2; i < 21; i++)
   {
      factor_map fmap;
      get_factors(i, primes, fmap);

      for(factor_map::iterator it = fmap.begin(); it != fmap.end(); ++it)
      {
         if(it->second > greatest[it->first])
            greatest[it->first] = it->second;
      }
   }

   unsigned int ttl = 1;
   for(factor_map::iterator it = greatest.begin(); it != greatest.end(); ++it)
   {
      for(int i = 0; i < it->second; i++)
      {
         ttl *= it->first;
      }
   }

   std::cout<< ttl << std::endl;
   return 0;
}
