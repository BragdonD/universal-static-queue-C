#include <stdlib.h>
#include <string.h>
#include "static_queue.h"

static_queue* create_pStaticQueue() {
    static_queue* temp = NULL;
    temp = malloc(sizeof(static_queue));
    return temp;
}

static_queue* staticQueue_init(size_t elm_size, int max_size) {
    static_queue* temp = create_pStaticQueue();
    if(temp == NULL) return NULL;

    temp->arr = calloc(max_size, elm_size);
    if(temp->arr == NULL) return NULL;
    temp->elem_size = elm_size;
    temp->front_index = 0;
    temp->rear_index = 0;
    temp->max_size = max_size;
    return temp;  
}

unsigned staticQueue_size(static_queue* queue) {
    return queue->rear_index - queue->front_index;
}

bool staticQueue_isEmpty(static_queue* queue) {
    return staticQueue_size(queue) == 0;
}

void staticQueue_empty(static_queue* queue) {
    queue->front_index = 0;
    queue->rear_index = 0;
}

void* staticQueue_front(static_queue* queue) {
    return (char*)(queue->arr) + (queue->front_index * queue->elem_size);
}

void* staticQueue_end(static_queue* queue) {
    return (char*)(queue->arr) + ((queue->rear_index - 1) * queue->elem_size);
}

bool staticQueue_push(static_queue* queue, void* elem) {
    int insert_index = queue->rear_index >= queue->max_size ? 0 : queue->rear_index;
    if(insert_index == queue->front_index && !staticQueue_isEmpty(queue)) return false;
    memcpy(((char*) queue->arr) + (insert_index) * queue->elem_size, elem, queue->elem_size);
    queue->rear_index = insert_index + 1;
    return true;
}

void* staticQueue_pop(static_queue* queue) {
    void *pop_elem = NULL;
    if(staticQueue_isEmpty(queue)) return NULL;
    pop_elem = (char*)queue->arr + queue->front_index * queue->elem_size;
    queue->front_index = queue->front_index + 1 > queue->max_size - 1 ? 0 : queue->front_index + 1;
    return pop_elem;
}

bool resize(static_queue* queue, int size) {
    return false;
}