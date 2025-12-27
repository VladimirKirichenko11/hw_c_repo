#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BITS 32  // Количество бит для представления

// Функция для перевода положительного числа в двоичный вид
void intToBinary(unsigned int num, char* binary) {
    for (int i = BITS - 1; i >= 0; i--) {
        binary[BITS - 1 - i] = (num & (1 << i)) ? '1' : '0';
    }
    binary[BITS] = '\0';
}

// Функция для получения дополнительного кода отрицательного числа
void twosComplement(int num, char* binary) {
    unsigned int positive;
    if (num < 0) {
        // Получаем модуль числа
        positive = (unsigned int)(-num);
        // Инвертируем биты
        unsigned int inverted = ~positive;
        // Добавляем 1
        unsigned int twosComp = inverted + 1;
        intToBinary(twosComp, binary);
    }
    else
        // Для положительного числа используем прмяой код
        intToBinary((unsigned int)num, binary);
}

// Функция для сложения двух двоичных чисел
void addBinary(const char* bin1, const char* bin2, char* result) {
    int carry = 0;

    for (int i = BITS - 1; i >= 0; i--) {
        int bit1 = bin1[i] - '0';
        int bit2 = bin2[i] - '0';

        int sum = bit1 + bit2 + carry;
        result[i] = (sum % 2) + '0';
        carry = sum / 2;
    }
    result[BITS] = '\0';
}

// Функция для проверки является ли число отрицательным в доп. коде
int isNegativeTwosComplement(const char* binary) {
    return binary[0] == '1';
}

// Функция для перевода из дополнительного кода в десятичное число
int binaryToInt(const char* binary) {
    if (isNegativeTwosComplement(binary)) {
        // Для отрицательных чисел: инвертируем биты, добавляем 1, берём отрицательное
        unsigned int num = 0;
        // Преобразуем строку в число
        for (int i = 0; i < BITS; i++) {
            num = (num << 1) | (binary[i] - '0');
        }
        // Получаем положительное представление
        unsigned int inverted = ~num;
        unsigned int positive = inverted + 1;
        // Возвращаем как отрицательное число
        return -(int)positive;
    }
    else {
        // Для положительных чисел
        int result = 0;
        for (int i = 0; i < BITS; i++) {
            result = (result << 1) | (binary[i] - '0');
        }
        return result;
    }
}

// Функция для печати двоичного числа с разделением на байты
void printBinaryFormatted(const char* binary, const char* label) {
    printf("%s: ", label);
    // Печатаем знаковый бит отдельно
    printf("%c ", binary[0]);
    for (int i = 1; i < BITS; i++) {
        printf("%c", binary[i]);
        if ((i + 1) % 8 == 0 && i != BITS - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

// Функция для сложения в столбик с визуализацией
void printBinaryAddition(const char* bin1, const char* bin2, const char* sum) {
    printf("\nAdding up in a column:\n");
    printf("  ");
    printBinaryFormatted(bin1, " ");
    printf("+ ");
    printBinaryFormatted(bin2, " ");
    printf("  ");
    for (int i = 0; i < BITS + 9; i++) printf("-");
    printf("\n  ");
    printBinaryFormatted(sum, " ");
}

// Функция для удаления ведущих нулей
void printBinaryWithoutLeadingZeros(const char* binary) {
    int started = 0;
    for (int i = 0; i < BITS; i++) {
        if (!started && binary[i] == '1')
            started = 1;
        if (started)
            printf("%c", binary[i]);
    }
    if (!started)
        printf("0");
}

int main() {
    int num1, num2;
    char binary1[BITS + 1], binary2[BITS + 1], sumBinary[BITS + 1];
    // Ввод числе
    printf("Enter the first number (integer): ");
    scanf_s("%d", &num1);
    printf("Enter the second number (integer): ");
    scanf_s("%d", &num2);
    printf("\n======================================\n");
    printf("    INPUT DATA\n");
    printf("========================================\n\n");
    printf("First number: %d\n", num1);
    printf("Second number: %d\n", num2);
    printf("\n======================================\n");
    printf("   BINARY (%d-bited)\n", BITS);
    printf("========================================\n\n");
    // Получаем двоичное представление в дополнительном коде
    twosComplement(num1, binary1);
    twosComplement(num2, binary2);
    // Печатаем двоичное представление
    printBinaryFormatted(binary1, "Number 1");
    printf("  (in compact: ");
    printBinaryWithoutLeadingZeros(binary1);
    printf(")\n\n");
    printBinaryFormatted(binary2, "Number 2");
    printf("  (in compact: ");
    printBinaryWithoutLeadingZeros(binary2);
    printf(")\n");
    printf("\n======================================\n");
    printf("          ADDITION PROCESS\n");
    printf("========================================\n\n");
    // Сложение двоичных чисел
    addBinary(binary1, binary2, sumBinary);
    // Выводим сложение в столбик
    printBinaryAddition(binary1, binary2, sumBinary);
    printf("\n\n====================================\n");
    printf("           RESULTS\n");
    printf("========================================\n\n");
    // Выводим сумму в двоичном виде
    printf("Sum in binary:\n");
    printBinaryFormatted(sumBinary, "Result");
    printf("  (in compact: ");
    printBinaryWithoutLeadingZeros(sumBinary);
    printf(")\n\n");
    // Переводим сумму обратно в десятичную систему
    int sumDecimal = binaryToInt(sumBinary);
    printf("Sum in int: %d\n", sumDecimal);
    int directSum = num1 + num2;
    printf("%d + %d = %d\n",
        num1, num2, directSum);

    return 0;
}
