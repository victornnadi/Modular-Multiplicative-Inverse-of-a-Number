// C program to find multiplicative inverse of a number using
// the euclidean algorithm.
#include <stdio.h>

// prototyping function for Euclidean Algorithm
int EuclidGCD(int a, int b, int* x, int* y);

// function to find multiplicative inverse of a
void multInverse(int a, int m)
{
	int x, y;
	int g = EuclidGCD(a, m, &x, &y);
	if (g != 1)
		printf("Inverse doesn't exist");
	else
	{
		// add m to handle -ve x
		int res = (x % m + m) % m;
		printf("multiplicative inverse of %d is %d", a, res);
	}
}

// function for Euclidean Algorithm
int EuclidGCD(int a, int b, int* x, int* y)
{

	if (a == 0)
	{
		*x = 0, *y = 1;
		return b;
	}

	int x1, y1;
	int gcd = EuclidGCD(b % a, a, &x1, &y1);


	*x = y1 - (b / a) * x1;
	*y = x1;

	return gcd;
}


int main()
{
	int a , m;
	//get input from user
	printf("Enter the number: ");
	scanf("%d", &a);
	printf("Enter the modulo: ");
	scanf("%d", &m);

	// Function call
	multInverse(a, m);
	return 0;
}
