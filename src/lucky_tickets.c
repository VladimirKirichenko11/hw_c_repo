#include <stdio.h>

int main() {
    int total = 0;
    int count[28] = { 0 };
    for (int a = 0; a < 10; a++) {
        for (int b = 0; b < 10; b++) {
            for (int c = 0; c < 10; c++) {
                count[a + b + c]++;
            }
        }
    }
    for (int sum = 0; sum < 28; sum++)
            total += count[sum] * count[sum];
    printf("Quantity of lucky tickets = %d\n", total);

	return 0;
}