#include <stdio.h>
#include <stdbool.h>


// Функция сравнения двух двоичных чисел
int compareBinaryNumbers(bool* num1, bool* num2, int size1, int size2) {
	// Еслли одно число в двоичной длиннее другого, то оно больше
	if (size1 > size2)
		return 1;
	else if (size1 < size2)
		return -1;
	for (int i = 0; i < size1; i++) {
		if (num1[i] > num2[i])
			return 1;
		else if (num1[i] < num2[i])
			return -1;
	}
	return 0; // Если биты равны
}


// Функция для удаления ведущих нулей
bool* removeLeadingZeros(bool* number, int* size) {
	int start = 0;
	while (start < *size && number[start] == 0)
		start++;
	// Если все биты нули - оставляем один ноль
	if (start == *size)
		start = *size - 1;
	// Корректировка указателя и размера
	*size -= start;
	return &number[start];
}


// Функция печати двочиного числа
void printBinary(bool* number, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d", number[i] ? 1 : 0);
	}
}


int main() {
	bool binary1[] = {0, 1, 1};
	bool binary2[] = {1, 0, 1};
	int size1 = sizeof(binary1) / sizeof(binary1[0]);
	int size2 = sizeof(binary2) / sizeof(binary2[0]);
	printf("First number: ");
	printBinary(binary1, size1);
	printf("\n");
	printf("Second number: ");
	printBinary(binary2, size2);
	printf("\n");
	// Убираем ведущие нули
	bool* clean1 = removeLeadingZeros(binary1, &size1);
	bool* clean2 = removeLeadingZeros(binary2, &size2);
	int result = compareBinaryNumbers(clean1, clean2, size1, size2);
	if (result == 1)
		printf("First number bigger than second\n");
	else if (result == -1)
		printf("Second number bigger than first\n");
	else
		printf("Numbers are equal\n");
	
	return 0;
}