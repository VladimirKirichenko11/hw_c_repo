#include <stdio.h>
#include <stdlib.h>

int main() {
	int size;
	printf("Enter size of array: ");
	scanf_s("%d", &size);
	if (size <= 0)
		printf("Incorrect array size\n");
	int *arr = (int*)malloc(size * sizeof(int));
	printf("Enter the elements of array: ");
	for (int i = 0; i < size; i++)
		scanf_s("%d", &arr[i]);
	int counter = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] == arr[0])
			counter++;
	}
	printf("Array: ");
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
	printf("Number of zero elements = %d\n", counter);

	return 0;
}