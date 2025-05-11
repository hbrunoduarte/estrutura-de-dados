#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
    int head; //index
    int tail; //index
    int size;
    int* array;
} Queue;

Queue* createQueue(int size) {
    Queue* newQueue = malloc(sizeof(Queue));
    newQueue->size = size;
    newQueue->array = malloc(sizeof(int)*size);

    newQueue->head = 0;
    newQueue->tail = 0;

    return newQueue;
}

int enqueue(Queue* queue, int value) {
    if(isFull(queue)) {
        printf("Queue Overflow\n");
        return 0;
    }
    queue->array[queue->tail] = value;
    queue->tail++;
    return 1;
}

int dequeue(Queue* queue, int* value) {
    if(isEmpty(queue)) {
        printf("Queue Underflow\n");
        return 0;
    }
    *value = queue->array[queue->head];

    for(int i = 1; i < queue->tail; i++) {
        queue->array[i - 1] = queue->array[i];
    }

    queue->tail--;
    queue->head = 0;

    return 1;
}

int seekHead(Queue* queue, int* value) {
    if(isEmpty(queue)) {
        printf("Queue is empty\n");
        return 0;
    }
    *value = queue->array[queue->head];
    return 1;
}

int seekTail(Queue* queue, int* value) {
    if(isEmpty(queue)) {
        printf("Queue is empty\n");
        return 0;
    }
    *value = queue->array[queue->tail-1];
    return 1;
}

void resetQueue(Queue* queue) {
    queue->head = 0;
    queue->tail = 0;
    
}

void destroyQueue(Queue* queue) {
    free(queue->array);
    free(queue);
}

int isEmpty(Queue* queue) {
    return queue->tail == queue->head;
}

int isFull(Queue* queue) {
    return queue->tail == queue->size;
}