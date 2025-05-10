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
    } else {
        queue->array[queue->tail] = value;
        queue->tail = nextPosition(queue->tail, queue->size);
        return 1;
    }
}

int dequeue(Queue* queue, int* value) {
    if(isEmpty(queue)) {
        printf("Queue Underflow\n");
        return 0;
    } else {
        *value = queue->array[queue->head];
        queue->head = nextPosition(queue->head, queue->size);
        return 1;
    }
}

int seekHead(Queue* queue) {
    if(isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    } else {
        return queue->array[queue->head];
    }
}

int seekTail(Queue* queue) {
    if(isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    } else {
        int last = (queue->tail - 1 + queue->size) % queue->size;
        return queue->array[last];
    }
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
    if(nextPosition(queue->tail, queue->size) == queue->head) {
        return 1;
    } else {
        return 0;
    }
}

int isEmpty(Queue* queue) {
    if(queue->head == queue->tail) {
        return 1;
    } else {
        return 0;
    }
}