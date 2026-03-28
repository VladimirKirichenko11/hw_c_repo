#include <stdio.h>
#include <stdlib.h>

int main() {
	int size;
	printf("Input quantity of numbers: ");
	scanf_s("%d", &size);

	int* numbers = (int*)malloc(size * sizeof(int)); // Создаем массив для хранения чисел
	// Ввод чисел
	printf("Input %d numbers:\n", size);
	for (int i = 0; i < size; i++) {
		scanf_s("%d", &numbers[i]);
	}
	// Считаем сумму цифр
	int max_count = 0;

	int* counts = (int*)malloc(size * sizeof(int)); // Массив для хранения количества единиц

	for (int i = 0; i < size; i++) {
		int current_number = numbers[i];
		int count = 0; // Счетчик
		printf("Number %d: ", current_number);
		// Переводим числа в двочиную систему и считаем сумму цифр
		while (current_number > 0) {
			int last_digit = current_number % 2; 
			if (last_digit == 1) 
				count++; 
			current_number = current_number / 2;
		}
		printf("%d ones\n", count);
		counts[i] = count;
		// Проверка на новое максимальное значение
		if (count > max_count)
			max_count = count;
	}

	printf("Max count ones : %d\n ", max_count);
	printf("Numbers with this count: ");
	for (int i = 0; i < size; i++) {
		if (counts[i] == max_count) {
			printf("%d \n", numbers[i]);
		}
	}

	free(numbers);
	return 0;
}