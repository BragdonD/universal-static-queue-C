#ifndef STATIC_QUEUE_H
#define STATIC_QUEUE_H

#include <stdbool.h>

typedef struct static_queue {
    void* arr;
    size_t elem_size;
    int max_size;
    int front_index;
    int rear_index;
} static_queue;

static_queue* staticQueue_init(size_t elem_size, int max_size);
unsigned staticQueue_size(static_queue* queue);
bool staticQueue_isEmpty(static_queue* queue);
void staticQueue_empty(static_queue* queue);
void* staticQueue_front(static_queue* queue);
void* staticQueue_end(static_queue* queue);
bool staticQueue_push(static_queue* queue, void* elem);
void* staticQueue_pop(static_queue* queue);
bool resize(static_queue* queue, int size);

#endif