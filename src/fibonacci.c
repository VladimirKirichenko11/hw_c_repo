#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Input number of digit: ");
    scanf_s("%d", &n);
    if (n <= 0) {
        printf("Incorrect number\n");
        return 1;
    }

    // Создаем строку для цифр
    char digits[1000];
    int length = 0;

    // Инициализируем числа Фибоначчи
    long long fib0 = 0, fib1 = 1, fibn;

    // Добавляем первые два числа
    if (length < 1000) {
        digits[length] = '0';
        length++;
    }
    if (length < 1000) {
        digits[length] = '1';
        length++;
    }
    // Добавляем цифры в строку, пока не наберем нужно количество
    while (length < n && length < 1000) {
        fibn = fib0 + fib1;
        fib0 = fib1;
        fib1 = fibn;
        long long temp = fibn;
        char num_digits[20];
        int count = 0;
        // Если число 0
        if (temp == 0) {
            num_digits[0] = '0';
            count = 1;
        }
        else {
            // Получаем цифры в обратном порядке
            while (temp > 0) {
                int digit = temp % 10;
                num_digits[count] = digit + '0';
                count++;
                temp = temp / 10;
            }
        }
        // Добавляем цифры в правильном порядке
        for (int i = count - 1; i >= 0; i--) {
            if (length < 1000) {
                digits[length] = num_digits[i];
                length++;
            }
        }
    }
    if (n <= length) {
        printf("%d digit: %c\n", n, digits[n - 1]);
    }
    else {
        printf("Big number. Max: %d\n", length);
    }

    return 0;
}