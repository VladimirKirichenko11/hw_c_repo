#include <stdio.h>
#include <stdint.h>

// Объединение для доступа к битам double
typedef union {
    double value;
    uint64_t bits;
} DoubleUnion;

// Структура для хранения разобранного числа double
typedef struct {
    int sign;          // Знак: 0 для +, 1 для -
    int exponent;      // Порядок (смещённый)
    uint64_t mantissa; // Мантисса (52 бита)
} DoubleComponents;

// Функция для получения i-го бита из 64 битного числа
int getBit(uint64_t num, int i) {
    return (num >> (63 - i)) & 1;
}

// Функция для разбора числа double на компоненты
DoubleComponents decomposeDouble(double num) {
    DoubleUnion du;
    du.value = num;
    DoubleComponents dc;
    // Извлекаем знак (бит 63)
    dc.sign = getBit(du.bits, 0);
    // Извлекаем порядок (биты 62-52)
    dc.exponent = 0;
    for (int i = 1; i <= 11; i++)
        dc.exponent = (dc.exponent << 1) | getBit(du.bits, i);
    // Извлекаем мантиссу (биты 51-0)
    dc.mantissa = 0;
    for (int i = 12; i < 64; i++)
        dc.mantissa = (dc.mantissa << 1) | getBit(du.bits, i);

    return dc;
}

// Функция для вычесления значений мантиссы как дробной части
double calculateMantissaValue(uint64_t mantissa_bits, int exponent) {
    double mantissa;
    if (exponent == 0)
        // Денормализованные числа: неявная ведущая 0
        mantissa = 0.0;
    else
        // Нормализованные числа: неявная ведущая 1
        mantissa = 1.0;
    // Добавляем дробные биты
    double fraction = 0.5;
    uint64_t mask = (1ULL << 51); // Маска для старшего бита мантиссы
    for (int i = 0; i < 52; i++) {
        if (mantissa_bits & mask) {
            mantissa += fraction;
        }
        fraction /= 2.0;
        mask >>= 1;
    }

    return mantissa;
}

// Функция для нормализации мантиссы и экспоненты
void normalizeMantissa(double* mantissa, int* exponent) {
    if (*mantissa == 0.0) {
        *exponent = 0;
        return;
    }
    if (*exponent == 0) {
        // Денормализованное число
        while (*mantissa < 1.0) {
            *mantissa *= 2.0;
            (*exponent)--;
        }
    }
    else {
        // Нормализованное число - уже должно быть в диапозоне [1.0, 2.0)
        while (*mantissa >= 2.0) {
            *mantissa /= 2.0;
            (*exponent)++;
        }
        while (*mantissa < 1.0 && *mantissa > 0.0) {
            *mantissa *= 2.0;
            (*exponent)--;
        }
    }
}

// Функция для форматированного вывода мантиссы
void printMantissa(double mantissa) {
    char buffer[50];
    sprintf_s(buffer, "%.20f", mantissa);
    // Удаляем незначащие нули в конце
    int len = 0;
    while (buffer[len] != '\0') len++;
    // Ищем точку
    int dot_pos = -1;
    for (int i = 0; i < len; i++) {
        if (buffer[i] == '.') {
            dot_pos = i;
            break;
        }
    }
    if (dot_pos != -1) {
        // Удаляем нули с конца
        int i = len - 1;
        while (i > dot_pos && buffer[i] == '0') {
            buffer[i] = '\0';
            i--;
        }
        // Если после удаления осталась только точка, удаляем и её
        if (i == dot_pos) {
            buffer[dot_pos] = '\0';
        }
    }
    printf("%s", buffer);
}

int main() {
    double number;
    printf("Enter a number: ");
    scanf_s("%lf", &number);
    // Разбираем число на компоненты
    DoubleComponents dc = decomposeDouble(number);
    // Вычисляем реальную экспоненту (со смещением 1023)
    int real_exponent;
    if (dc.exponent == 0)
        // Денормализованное число: экспонента = -1022
        real_exponent = -1022;
    else
        // Нормализованное число: экспонента = смещённый - 1023
        real_exponent = dc.exponent - 1023;
    // Вычисляем значение мантиссы
    double mantissa_value = calculateMantissaValue(dc.mantissa, dc.exponent);
    normalizeMantissa(&mantissa_value, &real_exponent);
    printf("Result: ");
    printf("%c", dc.sign ? '-' : '+');
    printMantissa(mantissa_value);
    printf("*2^%d\n", real_exponent);

    return 0;
}
