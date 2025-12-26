#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "vector.h"

// Структура, описывающая одну навигационную точку
typedef struct {
    size_t id;
    double latitude;
    double longitude;
    uint8_t signal;
} NavPoint;

// Функция для освобождения памяти
void free_navpoint(void* ptr) {
    free(ptr);
}

// Функция для копирования
NavPoint* navpoint_copy(const NavPoint* src) {
    if (!src) return NULL;
    NavPoint* copy = (NavPoint*)malloc(sizeof(NavPoint));
    if (!copy) return NULL;
    copy->id = src->id;
    copy->latitude = src->latitude;
    copy->longitude = src->longitude;
    copy->signal = src->signal;
    return copy;
}

// Функция для фильтрации надёжных точек
Vector* filter_reliable_points(Vector* points, uint8_t minSignal) {
    Vector* result = vector_create();
    if (!result) return NULL;
    for (size_t i = 0; i < vector_size(points); i++) {
        NavPoint* point = (NavPoint*)vector_at(points, i);
        if (!point) continue;
        if (point->signal >= minSignal) {
            NavPoint* copy = navpoint_copy(point);
            if (copy) {
                vector_push_back(result, copy);
            }
        }
    }

    return result;
}

// Функция анализа отфильтрованных точек
void analyze_reliable_points(Vector* reliablePoints) {
    if (!reliablePoints || vector_size(reliablePoints) == 0) {
        printf("No reliable points to analyze\n");
        return;
    }
    size_t count = vector_size(reliablePoints);
    printf("Number of reliable points: %zu\n", count);
    double sum_signal = 0;
    uint8_t max_signal = 0;
    size_t max_signal_id = 0;
    for (size_t i = 0; i < count; i++) {
        NavPoint* point = (NavPoint*)vector_at(reliablePoints, i);
        if (!point) continue;
        sum_signal += point->signal;
        if (point->signal > max_signal) {
            max_signal = point->signal;
            max_signal_id = point->id;
        }
    }
    double avg_signal = sum_signal / count;
    printf("Average signal level: %.2f\n", avg_signal);
    printf("Point with highest signal (ID: %zu, signal: %u)\n",
        max_signal_id, max_signal);
}

int main() {
    // Создаём массив точек
    Vector* points = vector_create();
    // Добавляем тестовые данные
    NavPoint* p1 = (NavPoint*)malloc(sizeof(NavPoint));
    p1->id = 1;
    p1->latitude = 55.7558;
    p1->longitude = 37.6173;
    p1->signal = 200;
    vector_push_back(points, p1);

    NavPoint* p2 = (NavPoint*)malloc(sizeof(NavPoint));
    p2->id = 2;
    p2->latitude = 55.7601;
    p2->longitude = 37.6185;
    p2->signal = 50;
    vector_push_back(points, p2);

    NavPoint* p3 = (NavPoint*)malloc(sizeof(NavPoint));
    p3->id = 3;
    p3->latitude = 55.7653;
    p3->longitude = 37.6198;
    p3->signal = 220;
    vector_push_back(points, p3);

    // Тестируем
    printf("Filtering points with minSignal = 100\n");
    Vector* reliable = filter_reliable_points(points, 100);

    printf("\nAnalysis of reliable points\n");
    analyze_reliable_points(reliable);
    // Очистка памяти
    // Уничтожаем исходный массив с его элементами
    vector_destroy(points, free_navpoint);
    // Уничтожаем отфильтрованный массив с его элементами
    vector_destroy(reliable, free_navpoint);

    return 0;
}
