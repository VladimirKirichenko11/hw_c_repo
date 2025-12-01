#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>


// Создание структуры узла связонного спска
// Каждый узел содержит целочисленное значение и указатель на следующий узел
typedef struct ListNode {
	int value;
	struct ListNode* next;
} ListNode;


// Создание нового узла списка
ListNode* list_create_node(int value) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode)); // Выделение памяти
	if (node == NULL) {
		fprintf(stderr, "Error memory giving for a node\n");
		exit(EXIT_FAILURE);
	}
	node->value;
	node->next = NULL;
	return node;
}

// Освобождение памяти узлов списка
void list_free(ListNode* head) {
	while (head != NULL) {
		ListNode* temp = head;
		head = head->next;
		free(temp);
	}
}

// Дбавление элемента в начало списка
ListNode* list_prepend(ListNode* head, int value) {
	ListNode* new_node = list_create_node(value);
	new_node->next = head;
	return new_node;
}

// Разворот списка
ListNode* list_reverse(ListNode* head) {
	ListNode* reversed = NULL;
	ListNode* current = head;
	while (current != NULL) {
		reversed = list_prepend(reversed, current->value);
		current = current->next;
	}
	return reversed;
}


// Получение длины списка
int list_lenght(ListNode* head) {
	int lenght = 0;
	while (head != NULL) {
		lenght++;
		head = head->next;
	}
	return lenght;
}


bool list_is_empty(ListNode* head) {
	return head == NULL;
}


// Реализация функциональной очереди
typedef struct FuncQueue {
	ListNode* front; // Элементы в правильном порядке
	ListNode* rear; // Элементы в обратном порядке
} FuncQueue;


// Создание новой пустой очереди
FuncQueue* queue_create() {
	FuncQueue* queue = (FuncQueue*)malloc(sizeof(FuncQueue));
	if (queue == NULL) {
		fprintf(stderr, "Error memory giving\n");
		exit(EXIT_FAILURE);
	}
	queue->front = NULL;
	queue->rear = NULL;
	return queue;
}

// Проверка очереди на пустоту
bool queue_is_empty(FuncQueue* queue) {
	return list_is_empty(queue->front) && list_is_empty(queue->rear);
}

// Просмотр верхнего элемента
bool queue_peek(FuncQueue* queue, int* result) {
	if (queue_is_empty(queue))
		return false;
	*result = queue->front->value;
	return true;
}

// Освобождение памяти, занятой очередью
void queue_free(FuncQueue* queue) {
	if (queue != NULL) {
		list_free(queue->front);
		list_free(queue->rear);
		free(queue);
	}
}

// Получение размера очереди
int queue_size(FuncQueue* queue) {
	return list_lenght(queue->front) + list_lenght(queue->rear);
}