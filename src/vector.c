#include "vector.h"
#include <stdlib.h>

typedef struct {
    void** data;        // Указатели на элементы
    size_t size;        // Текущее количество элементов
    size_t capacity;    // Вместимость
} Vector;

// Создание нового вектора
Vector* vector_create() {
    Vector* vec = (Vector*)malloc(sizeof(Vector));
    if (!vec) return NULL;
    vec->capacity = 4;
    vec->size = 0;
    vec->data = (void**)malloc(vec->capacity * sizeof(void*));
    if (!vec->data) {
        free(vec);
        return NULL;
    }

    return vec;
}

// Увелечение ёмкости вектора
static int vector_resize(Vector* vec, size_t new_capacity) {
    if (!vec) return 0;
    void** new_data = (void**)realloc(vec->data, new_capacity * sizeof(void*));
    if (!new_data) return 0;
    vec->data = new_data;
    vec->capacity = new_capacity;
    return 1;
}

// Добавление элемента в конец
int vector_push_back(Vector* vec, void* element) {
    if (!vec) return 0;
    // Если нужно увеличить ёмкость
    if (vec->size >= vec->capacity) {
        if (!vector_resize(vec, vec->capacity * 2)) {
            return 0;
        }
    }
    vec->data[vec->size] = element;
    vec->size++;
    return 1;
}

// Получение элемента по индексу
void* vector_at(Vector* vec, size_t index) {
    if (!vec || index >= vec->size) {
        return NULL;
    }
    return vec->data[index];
}

// Получение текущего размера
size_t vector_size(Vector* vec) {
    return vec ? vec->size : 0;
}

// Очистка вектора только структура (не элементы)
void vector_clear(Vector* vec) {
    if (vec) {
        vec->size = 0;
    }
}

// Удаление вектора с высвобождением памяти
// Используем callback для освобождения каждого элемента
void vector_destroy(Vector* vec, void (*free_element)(void*)) {
    if (!vec) return;
    // Если передан callback для освобождения элемента
    if (free_element) {
        for (size_t i = 0; i < vec->size; i++) {
            free_element(vec->data[i]);
        }
    }
    free(vec->data);
    free(vec);
}

// Удаление вектора без освобождения элементов (просто структура)
void vector_destroy_simple(Vector* vec) {
    if (!vec) return;
    free(vec->data);
    free(vec);
}
