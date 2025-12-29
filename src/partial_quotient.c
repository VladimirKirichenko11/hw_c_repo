#include <stdio.h>
#include <stdlib.h>

int main() {
	int a, b;
	printf("Enter first number: ");
	scanf_s("%d", &a);
	printf("Enter second number: ");
	scanf_s("%d", &b);
    if (b == 0) {
        printf("Error: division by zero\n");
        return 1;
    }
    int q = 0;
    int r = a;
    if (b > 0) {
        if (a >= 0) {
            while (r >= b) {
                r -= b;
                q++;
            }
        }
        else {
            while (r < 0) {
                r += b;
                q--;
            }
        }
    }
    else {
        if (a >= 0) {
            while (r >= 0) {
                r += b;
                q--;
            }
            r -= b;
            q++;
        }
        else {
            while (r <= b) {
                r -= b;
                q++;
            }
        }
    }
	printf("Quotient = %d\n", q);
	printf("Remainder = %d\n", r);

	return 0;
}
