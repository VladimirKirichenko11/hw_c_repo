#ifnded VECTOR_H
#define VECTOR_H

#include <stdlib.h>

typedef struct {
	void** data;
	size_t size;
	size_t capacity;
} Vector;

Vector* vector_create();
int vector_push_back(Vector* vec, void* element);
void* vector_at(Vector* vec, size_t index);
size_t vector_size(Vector* vec);
void* vector_destroy(Vector* vec, void (*free_element)(void*));
void vector_destroy_simple(Vector* vec);

#endif