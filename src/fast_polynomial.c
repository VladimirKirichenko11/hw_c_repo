#include <stdio.h>

int main()
{
	int x;
	printf("Enter the x: ");
	scanf_s("%d", &x);
	// x^4 + x^3 + x^2 + x + 1
	// (x^2 + x)(x^2 + 1) + 1
	const int step1 = x * x;
	const int step2 = step1 + x;
	const int step3 = step1 + 1;
	const int step4 = step2 * step3;
	const int result = step4 + 1;
	printf("Result: %d\n", result);

	return 0;
}