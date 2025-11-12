#include <stdio.h>

int main() {
	int number[6];
	int counter = 0;
	// Получаем номера билетов с помощью вложенных циклов
	for (number[0] = 0; number[0] <= 9; number[0]++) {
		for (number[1] = 0; number[1] <= 9; number[1]++) {
			for (number[2] = 0; number[2] <= 9; number[2]++) {
				for (number[3] = 0; number[3] <= 9; number[3]++) {
					for (number[4] = 0; number[4] <= 9; number[4]++) {
						for (number[5] = 0; number[5] <= 9; number[5]++) {
							if (number[0] + number[1] + number[2] == number[3] + number[4] + number[5])
								counter++;
						}
					}
				}
			}
		}
	}
	printf("%d\n", counter);

	return 0;
}