#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "stack.h"


// Функция для определения приоритета оператора
int getPriority(char op) {
    switch (op) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return 0;
    }
}


// Функция проверки, является ли символ оператором
int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}


// Основная функция преобразования
void infixToPostfix(char* infix, char* postfix) {
    CharStack stack;
    initStack(&stack); // Инициализируем стек
    int j = 0; // Индекс для записи в выходную строку
    for (int i = 0; i < strlen(infix); i++) {
        char current = infix[i];
        if (current == ' ') continue; // Пропускаем пробелы
        if (isdigit(current)) {
            postfix[j++] = current;
            postfix[j++] = ' '; // Добавляем пробел для разделения операндов
        }
        else if (current == '(') {
            push(&stack, current); // Кладём открывающую скобку в стек
        }
        else if (current == ')') {
            while (!isEmpty(&stack) && peek(&stack) != '(') { // Пока стек не пуст и наверху не '('
                postfix[j++] = pop(&stack); // Извлекаем операторы из стека в выходную строку
                postfix[j++] = ' '; // Пробелы для разделения
            }
            pop(&stack); // Извлекаем '('
        }
        else if (isOperator(current)) {
            while (!isEmpty(&stack) &&
                getPriority(peek(&stack)) >= getPriority(current) &&
                peek(&stack) != '(') { // Пока в стеке есть операторы с высшим или равным приоритетом и они не '('
                postfix[j++] = pop(&stack); // Извлекаем их в выходную строку
                postfix[j++] = ' ';
            }
            push(&stack, current); // Кладём текущий оператор в стек
        }
    }
    while (!isEmpty(&stack)) { // Пока стек не пуст
        postfix[j++] = pop(&stack); // Извлекаем оставшееся из стека
        postfix[j++] = ' ';
    }

    postfix[j] = '\0';
}


int main() {
    char str_1[] = "(3 + 1) * 4";
    char str_2[] = "3 + 1 * 4";
    char result[100];
    infixToPostfix(str_1, result);
    printf("'%s' -> '%s'\n", str_1, result);
    infixToPostfix(str_2, result);
    printf("'%s' -> '%s'\n", str_2, result);

    return 0;
}