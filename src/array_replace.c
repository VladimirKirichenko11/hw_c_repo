#include <stdio.h>

// Функция для обращения порядка элементов массива
void reverse(int array[], int start, int end)
{
	while (start < end) {
		int temp = array[start];
		array[start] = array[end];
		array[end] = temp;
		start++;
		end--;
	}
}

// Функция для перестановки частей массива
void switchSegments(int array[], int m, int n)
{
	reverse(array, 0, m + n - 1);
	reverse(array, 0, n - 1);
	reverse(array, n, m + n - 1);
}

// Функция вывода массива
void printArray(int array[], int size)
{
	for (int i = 0; i < size; i++) 
		printf("%d ", array[i]);
	printf("\n");
}

int main()
{
	int m = 4, n = 5;
	int total_size = m + n;
	int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	printf("Original array: ");
	printArray(array, total_size);
	switchSegments(array, m, n);
	printf("After replace: ");
	printArray(array, total_size);

	return 0;
}
