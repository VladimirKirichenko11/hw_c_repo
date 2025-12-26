#include <stdio.h>
#include <stdlib.h>

// Структура узла списка
struct Node {
    int data;
    struct Node* next;
};

// Функция для созданния нового узла
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation error\n");
        return NULL;
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Функция добавления значения в список
void addToSortedList(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (newNode == NULL) return;
    // Если список пуст или новыйй элемент меньше первого
    if (*head == NULL || (*head)->data >= value) {
        newNode->next = *head;
        *head = newNode;
        printf("Value %d added to the list\n", value);
        return;
    }
    // Поиск места для вставки
    struct Node* current = *head;
    while (current->next != NULL && current->next->data < value) {
        current = current->next;
    }
    // Вставляем новый узел
    newNode->next = current->next;
    current->next = newNode;
    printf("Value %d was added to the list\n", value);
}

// Функция для удаления значения из списка
void deleteFromList(struct Node** head, int value) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    // Если удаляем первый элемент
    if ((*head)->data == value) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        printf("Value %d was deleted from the list\n", value);
        return;
    }
    // Ищем элемент для удаления
    struct Node* current = *head;
    while (current->next != NULL && current->next->data != value) {
        current = current->next;
    }
    // Если элемент не найден
    if (current->next == NULL) {
        printf("Value %d was not found in the list\n", value);
        return;
    }
    // Удаляем элемент
    struct Node* temp = current->next;
    current->next = current->next->next;
    free(temp);
    printf("Value %d was deleted from the list\n", value);
}

// Функция печати списка
void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Current list: ");
    struct Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf(" -> NULL\n");
}

// Функция для освобождения памяти
void freeList(struct Node** head) {
    struct Node* current = *head;
    struct Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

// Функция для отображения меню
void printMenu() {
    printf("\n========= MENU =========\n");
    printf("0 - Exit\n");
    printf("1 - Add value to the sorted list\n");
    printf("2 - Delete value from the list\n");
    printf("3 - Print the list\n");
    printf("==========================\n");
    printf("Choose action: ");
}

int main() {
    struct Node* head = NULL; // Начинаем с пустого списка
    int choice, value;

   // printf("=== СОРТИРОВАННЫЙ СПИСОК ===\n");

    do {
        printMenu();
        scanf_s("%d", &choice);

        switch (choice) {
        case 0:
            printf("Exit from programm...\n");
            break;

        case 1:
            printf("Enter the value for addition: ");
            scanf_s("%d", &value);
            addToSortedList(&head, value);
            break;

        case 2:
            printf("Enter the value for deletion: ");
            scanf_s("%d", &value);
            deleteFromList(&head, value);
            break;

        case 3:
            printList(head);
            break;

        default:
            printf("Wrong choice. Please, try again\n");
            break;
        }

    } while (choice != 0);

    // Освобождаем память
    freeList(&head);

    return 0;
}