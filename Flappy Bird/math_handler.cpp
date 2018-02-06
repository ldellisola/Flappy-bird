#include "math_handler.h"
int power(int base, int exp)
{
	int counter, num = 1;
	for (counter = 1; counter <= exp; ++counter)
	{
		num = num * base;
	}
	return num;
}