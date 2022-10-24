#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "static_queue.h"
#include "ui.h"

int main(int argc, char const *argv[])
{
    static_queue* queue = staticQueue_init(sizeof(int), 10);
    int elem = 0, choice = 0, *val = NULL;

    if(queue == NULL) return EXIT_FAILURE;

    do {
        Menu();
        choice = Choice();
        if(isWrongMenuChoice(choice)) continue;
        switch (choice)
        {
        case 1:
            printf("Write the value of the element to be insert : ");
            while(!getInt(&elem)) {
                printf("Failed to parse an integer from the input.\n");
            }
            if(!staticQueue_push(queue, &elem)) {
                printf("Failed to add element to queue.\n");
                continue;
            }
            break;
        case 2:
            val = (int*)staticQueue_front(queue);
            if(val == NULL) {
                printf("The queue is empty.\n");
                continue;
            }
            printf("Front element is : %d and is at index : %d.\n", *val, queue->front_index);
            break;
        case 3:
            val = (int*)staticQueue_end(queue);
            if(val == NULL) {
                printf("The queue is empty.\n");
                continue;
            }
            printf("Rear element is : %d and is at index : %d.\n", *val, queue->rear_index - 1);
            break;
        case 4: {
            int* dequeu_elem = NULL;
            dequeu_elem = (int*)staticQueue_pop(queue);
            if(dequeu_elem == NULL) {
                printf("Queue is empty !\n");
                continue;
            }
            printf("Dequeue an element which has the value %d\n", *dequeu_elem);
            break;
        }
        case 5:
            staticQueue_empty(queue, NULL);
            break;
        case 6:
            printf("Leaving...\n");
            break;
        default:
            printf("No action corresponding to the choice.\n");
            break;
        }
    } while(choice != 6);

    free(queue->arr);
    free(queue);
    return 0;
}