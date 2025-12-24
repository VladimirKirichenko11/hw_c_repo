#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a, b, quot = 0;
	printf("Enter first number: ");
	scanf_s("%d", &a);
	printf("Enter second number: ");
	scanf_s("%d", &b);
	int max, min;
	// Choosing a larger number a divinded, smaller - as divisor
	if (abs(a) >= abs(b))
		max = a, min = b;
	else
		max = b, min = a;
	if (min == 0) {
		printf("Error: division by zero\n");

		return 1;
	}
	// If number with different signs are entered
	if ((a > 0 && b < 0) || (b > 0 && a < 0)) {
		while (abs(max) - abs(min) >= 0) {
			max = -(abs(max) - abs(min));
			quot--;
		}
	}
	else {
		while (abs(max) - abs(min) >= 0) {
			max -= min;
			quot++;
		}
	}
	printf("Quotient = %d\n", quot);
	printf("Remainder = %d\n", abs(max));

	return 0;
}