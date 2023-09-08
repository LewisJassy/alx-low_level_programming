#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
/**
 * main - get random int and compare last digit to 0, 5 and 6
 *
 * Return: 0 always
 */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	if (n > 5)
	{
		printf("Last digit of %d is %d and is greater than 5\n", n, n % 10);
	}
	else if (n == 0)
	{
		printf("Last digit of %d is %d and is 0\n", n, n % 10);
	}
	else 
	{
		printf("Last digit of %d is %d and is less than 6 and not 0",n ,n % 10);
	}	
	return (0);
}
