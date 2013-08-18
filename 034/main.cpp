#include <iostream>
#include <vector>

#include "cpmath.h"

/*

145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.

Find the sum of all numbers which are equal to the sum of the factorial of their digits.

Note: as 1! = 1 and 2! = 2 are not sums they are not included.

*/

bool is_factorial_equal(int num)
{
	int digits = cp::math::get_num_digits(num);

	int orig = num;

	int sum = 0;
	int d = 0;
	for(int i = digits; i > 0; --i)
	{
		d = num % 10;
		sum += cp::math::get_factorial(d);
		if(sum > orig)
			return false;
	
		num = (num - d) / 10;
	}

	return orig == sum;
}

int main()
{
	int sum = 0;
	for(int i = 10; i < 10000000; ++i)
	{
		if(is_factorial_equal(i))
			sum += i;
	}

	std::cout<< sum << std::endl;
}
