#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* link;
} Node;

typedef struct queue {
    Node* head;
    Node* tail;
} Queue;

Queue* createQueue() {
    Queue* newQueue = malloc(sizeof(Queue));
    newQueue->head = NULL;
    newQueue->tail = NULL;

    return newQueue;
}

void enqueue(Queue* queue, int value) {
    Node* newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->link = NULL;

    if(queue->tail) {
        queue->tail->link = newNode;
    } else {
        queue->head = newNode;
    }

    queue->tail = newNode;
}

int dequeue(Queue* queue, int* value) {
    if(!queue->head) {
        printf("Queue Underflow\n");
        return 0;
    }

    Node* temp = queue->head;
    *value = temp->value;
    queue->head = temp->link;
    free(temp);

    if(!queue->head) {
        queue->tail = NULL;
    }

    return 1;
}

int seekHead(Queue* queue, int* value) {
    if(!queue->head) {
        printf("Queue is empty\n");
        return 0;
    }
    *value = queue->head->value;
    return 1;
}

int seekTail(Queue* queue, int* value) {
    if(!queue->tail) {
        printf("Queue is empty\n");
        return 0;
    }
    *value = queue->tail->value;
    return 1;
}

void resetQueue(Queue* queue) {
    while(queue->head) {
        Node* temp = queue->head;
        queue->head = queue->head->link;
        free(temp);
    }
    queue->tail = NULL;
}

void destroyQueue(Queue* queue) {
    resetQueue(queue);
    free(queue);
}