#ifndef STACK_H
#define STACK_H

#define MAX_SIZE 100

// Структура стека для символов
typedef struct {
    char data[MAX_SIZE];
    int top;
} CharStack;

void initStack(CharStack* s);
int isEmpty(CharStack* s);
int isFull(CharStack* s);
void push(CharStack* s, char c);
char pop(CharStack* s);
char peek(CharStack* s);

#endif