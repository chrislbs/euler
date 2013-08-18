#include <iostream>
#include <math.h>
#include <vector>
#include <unordered_map>

/*

The decimal number, 585 = 10010010012 (binary), is palindromic in both bases.

Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.

(Please note that the palindromic number, in either base, may not include leading zeros.)

*/

int binaryLen(int val)
{
	return static_cast<int>(log(val) / log(2)) + 1;
}

int decimalLen(int val)
{
	return static_cast<int>(log10(val)) + 1;
}

int pow10(int exp)
{
	static std::unordered_map<int, int> cache;

	if(cache.find(exp) == cache.end())
	{
		int val = 1;
		for(int i = 0; i < exp; ++i)
			val *= 10;

		cache[exp] = val;
	}

	return cache[exp];
}

int pow2(int exp)
{
	static std::unordered_map<int, int> cache;

	if(cache.find(exp) == cache.end())
	{
		int val = 1;
		for(int i = 0; i < exp; ++i)
			val *= 2;
	
		cache[exp] = val;
	}

	return cache[exp];
}

bool isDecimalPalindrome(int val)
{
	int len = decimalLen(val);

	for(int i = 0, j = len - 1; i < j; ++i, --j)
	{
		if((val / pow10(i)) % 10 != (val / pow10(j)) % 10)
			return false;
	}
	return true;
}

std::vector<bool> getBinary(int val)
{
	int len = binaryLen(val);
	int startVal = pow2(len - 1);
	std::vector<bool> bin;
	for(int i = 0; i < len; ++i)
	{
		bin.push_back(val >= startVal);
		val -= bin.back() ? startVal : 0;
		startVal /= 2;
	}

	return bin;
}

void printBinary(const std::vector<bool>& bin)
{
	for(int i = 0; i < bin.size(); ++i)
		std::cout<< bin[i];
}

bool isBinaryPalindrome(int val)
{
	std::vector<bool> bin = getBinary(val);
	for(int i = 0, j = bin.size() - 1; i < j; ++i, --j)
	{
		if(!(bin[i] == bin[j]))
			return false;
	}
	return true;
}

#define DEBUG

int main()
{
	const int UPPER_BOUND = 1000000;
	int palinSums = 0;
/*
0
1 - 1
10
11 - 3
100 
101 - 5
110
111 - 7
1000
1001 - 9
1010
1011
1100
1101
1110
1111 - 15
*/

	for(int i = 1; i < UPPER_BOUND; i += 2)
	{
		if(isDecimalPalindrome(i) && isBinaryPalindrome(i))
		{
			palinSums += i;

			#ifdef DEBUG

			std::cout<< i << '\t';
			printBinary(getBinary(i));
			std::cout<< std::endl;

			#endif
		}
	}
	
	std::cout<< palinSums;

	char c;
	std::cin>> c;
}
