#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>

#include "cpmath.h"
#include "cpprime.h"

/*

The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.

Find the sum of the only eleven primes that are both truncatable from left to right and right to left.

NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.

*/

std::unordered_set<int> primes;

bool is_trunc_left(int num)
{
	int digits = cp::math::get_num_digits(num);
	for(int i = digits; i > 0; --i)
	{
		if(primes.find(num) == primes.end())
			return false;

		num = num % static_cast<int>(pow(10, i -1));
	}

	return true;
}

bool is_trunc_right(int num)
{
	int digits = cp::math::get_num_digits(num);
	for(int i = digits; i > 0; --i)
	{
		if(primes.find(num) == primes.end())
			return false;

		num = (num - (num % 10)) / 10;
	}

	return true;
}

bool is_trunc(int num)
{
	return is_trunc_right(num) && is_trunc_left(num);
}

int main()
{
	const int MAX_PRIMES = 1000000;
	std::vector<int> primeContainer;
	cp::math::generate_primes(MAX_PRIMES, 
		std::back_inserter(primeContainer));

	std::cout<< primeContainer.size() << std::endl;
	std::cout<< cp::math::get_num_digits(primeContainer.size()) << std::endl;

	primes.insert(
		primeContainer.begin(), 
		primeContainer.end());

	int sum = 0;
	typedef std::vector<int>::iterator iter;
	for(iter it = primeContainer.begin(); it < primeContainer.end(); ++it)
	{
		if(*it < 10)
			continue;

		if(is_trunc(*it))
			sum += *it;
	}
	std::cout<< sum;

	char c;
	std::cin>> c;

	return 0;
}
