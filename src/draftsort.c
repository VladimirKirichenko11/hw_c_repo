#include <stdio.h>
#include <stdlib.h>

// Функция обмена значений
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

// Функция сортировки выбором
void draftSort(int arr[], int size) {
	for (int i = 0; i < size - 1; i++) {
		int min_index = i;
		// Проход по неотсортированной части массива
		for (int j = i + 1; j < size; j++) {
			if (arr[j] < arr[min_index]) {
				min_index = j;
			}
		}
		if (min_index != i)
			swap(&arr[min_index], &arr[i]); // Меняем местами минимальный элемент с первым в неотсортированной части
	}
}

// Функция вывода массива
void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main() {
	int size;
	printf("Input array size: ");
	scanf_s("%d", &size);
	if (size < 1)
		printf("Incorrect array size\n");

	int *arr = (int*)malloc(size * sizeof(int)); // Создаем массив, который будем сортировать

	printf("Input array elements: ");
	// Ввод элементов массива
	for (int i = 0; i < size; i++)
		scanf_s("%d", &arr[i]);
	printf("Unsorted array: ");
	printArray(arr, size);
	draftSort(arr, size);
	printf("Sorted array: ");
	printArray(arr, size);

	free(arr);
	return 0;
}