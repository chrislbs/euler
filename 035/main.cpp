#include <iostream>
#include <sstream>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <vector>

#include "sieve.h"

/*

The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.

There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.

How many circular primes are there below one million?

*/

std::unordered_set<int> primes;

void rotateString(std::string& str)
{
	std::string temp;
	temp = str.substr(1);
	temp += str[0];

	str = temp;
}

bool isCircularPrime(int num, std::vector<int>& outPerms)
{
	std::stringstream ss;
	std::string numStr;

	ss<< num;
	ss>> numStr;
	for(int i = 0; i < numStr.size(); ++i)
	{
		num = atoi(numStr.c_str());
		std::cout<< numStr << '\t' << num << std::endl;
		if(primes.find(num) == primes.end())
			return false;

		outPerms.push_back(num);

		rotateString(numStr);
	}

	return true;
}

int main()
{
	const int MAX_PRIMES = 1000000;
	std::vector<int> primeContainer;
	cp::math::generatePrimes(primeContainer, MAX_PRIMES);

	primes.insert(primeContainer.begin(), primeContainer.end());

	std::unordered_set<int> circular;

	typedef std::vector<int>::iterator iter;
	/*
	for(iter it = primeContainer.begin(); it != primeContainer.end(); ++it)
	{
		std::vector<int> perms;
		if(isCircularPrime(*it, perms))
			circular.insert(perms.begin(), perms.end());
	}
	*/

	std::string test = "179";
	for(int i = 0; i < test.size(); ++i)
	{
		std::cout<< test << '\t';
		rotateString(test);
	}
	std::cout<< std::endl;


	std::vector<int> perms;
	if(isCircularPrime(179, perms))
		circular.insert(perms.begin(), perms.end());

	std::cout<< circular.size() << std::endl;
}
