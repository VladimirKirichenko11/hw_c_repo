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
/*#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a, b, quot = 0;
	printf("Enter first number: ");
	scanf_s("%d", &a);
	printf("Enter second number: ");
	scanf_s("%d", &b);
	int max, min;
	// Выбор большего числа в качестве делимого, меньшего - делителя
	if (abs(a) >= abs(b))
		max = a, min = b;
	else
		max = b, min = a;
	if (min == 0) {
		printf("Error: division by zero\n");

		return 1;
	}
	// Если вводятся числа с разными знаками
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
	printf("Remainder = %d\n", max);

	return 0;
}*/