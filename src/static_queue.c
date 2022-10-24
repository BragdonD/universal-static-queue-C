#include <stdlib.h>
#include <string.h>
#include "static_queue.h"

/// @brief Function to create a static empty queue. It is not callable by the end user
/// @return Return an allocated pointer. NULL in case of error.
static_queue* create_pStaticQueue() {
    static_queue* temp = NULL;
    temp = malloc(sizeof(static_queue));
    return temp; ///Handle the malloc error in the caller function.
}

/// @brief Function to create a queue with a maximum size of element.
/// @param elm_size The type size to allocated the array.
/// @param max_size The size of the array to be allocated.
/// @return A pointer toward a created queue. Call staticQueue_free
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

/// @brief Function to get the size of a queue
/// @param queue A pointer toward a static queue.
/// @return the size of the queue.
unsigned staticQueue_size(static_queue* queue) {
    return queue->rear_index - queue->front_index;
}

/// @brief Function to test if the queue is empty. 
/// @param queue A pointer toward a static queue.
/// @return true or false.
bool staticQueue_isEmpty(static_queue* queue) {
    return staticQueue_size(queue) == 0;
}

/// @brief Function to reset the queue
/// @param queue a pointer toward a static queue.
/// @param free_data a function to free the data. You can pass NULL if you do want or need to free it.
void staticQueue_empty(static_queue* queue, void (*free_data)(void*)) {
    int len = staticQueue_size(queue);
    if(free_data != NULL)
        for(int i=0; i<len; i++) {
            free_data(staticQueue_pop(queue));
        }
    queue->front_index = 0;
    queue->rear_index = 0;
}

/// @brief Function to get the data at the front of the queue
/// @param queue a pointer toward a static queue
/// @return a pointer toward the data at the front of the queue
void* staticQueue_front(static_queue* queue) {
    if(staticQueue_isEmpty(queue)) return NULL;
    return (char*)(queue->arr) + (queue->front_index * queue->elem_size);
}

/// @brief Function to get the data at the end of the queue
/// @param queue a pointer toward a static queue
/// @return a pointer toward the data at the end of the queue
void* staticQueue_end(static_queue* queue) {
    if(staticQueue_isEmpty(queue)) return NULL;
    return (char*)(queue->arr) + ((queue->rear_index - 1) * queue->elem_size);
}

/// @brief Function to push an element at the end of a static queue.
/// @param queue A pointer toward a static queue.
/// @param elem A pointer toward the data to be inserted.
/// @return true on success. false if the queue is full.
bool staticQueue_push(static_queue* queue, void* elem) {
    int insert_index = queue->rear_index >= queue->max_size ? 0 : queue->rear_index;
    if(insert_index == queue->front_index && !staticQueue_isEmpty(queue)) return false;
    memcpy(((char*) queue->arr) + (insert_index) * queue->elem_size, elem, queue->elem_size);
    queue->rear_index = insert_index + 1;
    return true;
}

/// @brief Function to remove an element at the end of a static queue.
/// @param queue A pointer toward a static queue.
/// @return pointer toward the data to be retrieve. NULL on error.
void* staticQueue_pop(static_queue* queue) {
    void *pop_elem = NULL;
    if(staticQueue_isEmpty(queue)) return NULL;
    pop_elem = (char*)queue->arr + queue->front_index * queue->elem_size;
    queue->front_index = queue->front_index + 1 > queue->max_size - 1 ? 0 : queue->front_index + 1;
    return pop_elem;
}

/// @brief Function to resize the queue. Does not handle the memory of your data.
/// @param queue a pointer toward the queue to be resize.
/// @param size the new max size of the queue
/// @return true on success.
bool staticQueue_resize(static_queue* queue, int size) {
    void *arr = NULL;
    arr = realloc(queue->arr, size * queue->elem_size);
    if(arr == NULL) return false;
    queue->arr = arr;
    return false;
}

/// @brief Function to be call at the end to free the queue data.
/// @param queue a pointer toward the queue.
/// @param free_data a function to free you data. Can be NULL if you do not want or need to free it.
void staticQueue_free(static_queue* queue, void (*free_data)(void*)) {
    if(queue == NULL) return;
    int len = staticQueue_size(queue);
    if(free_data != NULL)
        for(int i=0; i<len; i++) {
            free_data(staticQueue_pop(queue));
        }
    free(queue->arr);
    free(queue);
}