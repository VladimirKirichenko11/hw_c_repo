#include "stack.h"

// Инициализация стека
void initStack(CharStack* s) {
    s->top = -1;
}

// Проверка, пуст ли стек
int isEmpty(CharStack* s) {
    return s->top == -1;
}

// Проверка, полон ли стек
int isFull(CharStack* s) {
    return s->top == MAX_SIZE - 1;
}

// Добавление элемента в стек
void push(CharStack* s, char c) {
    if (!isFull(s)) {
        s->data[++s->top] = c;
    }
}

// Извлечение элемента из стека
char pop(CharStack* s) {
    if (!isEmpty(s))
        return s->data[s->top--];
    return '\0';
}

// Просмотр верхнего элемента без извлечения
char peek(CharStack* s) {
    if (!isEmpty(s)) {
        return s->data[s->top];
    }
    return '\0';