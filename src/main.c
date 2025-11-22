#include <stdio.h>

extern int sort_array(int* array, int size);

int main() {
	int numbers[100];
	int count = 0;
	printf("Enter numbers: \n");
	while (count < 100 && scanf("%d", &numbers[count]) == 1)
		count++;
	printf("Before sorting: ");
	for (int i = 0; i < count; i++)
		printf("%d ", numbers[i]);
	printf("\n");
	int moved_count = sort_array(numbers, count);
	printf("After sorting: ");
	for (int i = 0; i < count; i++)
		printf("%d ", numbers[i]);
	printf("\n");

	return moved_count;
}
