#include <stdio.h>
#include <string.h>
#include "stack.h"

// Функция проверки, являются ли скобки парными
int isMatchingPair(char open, char close) {
	if (open == '(' && close == ')')
		return 1;
	if (open == '[' && close == ']')
		return 1;
	if (open == '{' && close == '}')
		return 1;
	return 0; // Если скобки непарные
}


// Основная функция проверки баланса скобок
int checkBalance(char* str) {
	CharStack stack;
	initStack(&stack); // Инициализируем стек
	// Проходимся по строке
	for (size_t i = 0; i < strlen(str); i++) {
		if (str[i] == '(' || str[i] == '[' || str[i] == '{')
			push(&stack, str[i]); // Кладём открывающую скобку в стек
		else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
			// Если стек пуст, а у нас закрывающая скобка - ошибка
			if (isEmpty(&stack))
				return 0;
			// Проверка на соответствие закрывающей скобки открывающей на вершине стека
			char topchar = pop(&stack);
			if (!isMatchingPair(topchar, str[i]))
				return 0;
		}
	}

	return isEmpty(&stack);
}


int main() {
	char str[] = "({})";
	if (checkBalance(str))
		printf("Correct!\n");
	else
		printf("Incorrect!\n");

	return 0;
}
