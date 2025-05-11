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
    newQueue->array = malloc(sizeof(int)*size);

    newQueue->size = size;

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
    queue->tail = nextPosition(queue->tail, queue->size);
    return 1;

}

int dequeue(Queue* queue, int* value) {
    if(isEmpty(queue)) {
        printf("Queue Underflow\n");
        return 0;
    }
    *value = queue->array[queue->head];
    queue->head = nextPosition(queue->head, queue->size);
    return 1;
}

int seekHead(Queue* queue, int* value) {
    if(isEmpty(queue)) {
        printf("Queue is empty\n");
        *value = NULL;
        return 0;
    }
    *value = queue->array[queue->head];
    return 1;
}

int seekTail(Queue* queue, int* value) {
    if(isEmpty(queue)) {
        printf("Queue is empty\n");
        *value = NULL;
        return 0;
    }
    int last = (queue->tail - 1 + queue->size) % queue->size;
    *value = queue->array[last];
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

int nextPosition(int index, int size) {
    return (index+1) % size;
}

int isFull(Queue* queue) {
    return nextPosition(queue->tail, queue->size) == queue->head;
}

int isEmpty(Queue* queue) {
    return queue->head == queue->tail;
}