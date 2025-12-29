#include <stdio.h>
#include <stdlib.h>

// Структура узла циклического списка
struct Warrior {
    int position;
    struct Warrior* next;  // Указатель на следующего воина
};

// Функция для создания цикличесского списка из n воинов
struct Warrior* createCircle(int n) {
    if (n <= 0) 
        return NULL;
    struct Warrior* head = NULL;
    struct Warrior* prev = NULL;
    struct Warrior* current = NULL;
    // Создаём n воинов
    for (int i = 1; i <= n; i++) {
        current = (struct Warrior*)malloc(sizeof(struct Warrior));
        current->position = i;
        if (head == NULL) {
            head = current;
        }
        else {
            prev->next = current;
        }
        prev = current;
    }
    // Замыкаем круг - последний указатель указывает на первого
    if (current != NULL) {
        current->next = head;
    }

    return head;
}

// Функция для решения задачи Иосифа Флавия
int rhyme(int n, int m) {
    if (n <= 0 || m <= 0) {
        printf("Incorrect parametrs\n");
        return -1;
    }
    // Создаём круг
    struct Warrior* current = createCircle(n);
    if (current == NULL) return -1;
    struct Warrior* prev = NULL;
    // Находим номер последнего элемента для замыкания круга
    prev = current;
    while (prev->next != current) {
        prev = prev->next;
    }
    // Устраняем воинов, пока не останется один
    while (current->next != current) {
        // Находим m-го воина
        for (int i = 1; i < m; i++) {
            prev = current;
            current = current->next;
        }
        // Устраняем m-го воина
        printf("Warrior on %d position was eliminated\n", current->position);
        prev->next = current->next;
        struct Warrior* toDelete = current;
        current = current->next;
        free(toDelete);
    }

    // Последний оставшийся воин
    int lastPosition = current->position;
    printf("\nThe last remaining warrior was on position %d\n", lastPosition);
    free(current);
    return lastPosition;
}

int main() {
    int n, m;
    // Ввод данных
    printf("Enter the number of warriors (n): ");
    scanf_s("%d", &n);
    printf("Enter the elimination step (m): ");
    scanf_s("%d", &m);
    rhyme(n, m);

    return 0;
}
