#include <stdio.h>
#include <stdlib.h>

typedef int (*CompareFunc)(void*, void*);
// a < b   ->   < 0
// a = b   ->     0
// a > b   ->   > 0

typedef enum {
    MIN = -1,
    MAX = 1
} PRIORITY_TYPE;

typedef struct node {
    void* data;
    struct node* link;
} Node;

typedef struct queue {
    Node* head;
    Node* tail;
    PRIORITY_TYPE pType;
    CompareFunc compare;
} Queue;

Queue* createQueue(PRIORITY_TYPE pType, CompareFunc cmp) {
    Queue* newQueue = malloc(sizeof(Queue));
    newQueue->head = NULL;
    newQueue->tail = NULL;
    newQueue->pType = pType;
    newQueue->compare = cmp;

    return newQueue;
}

void enqueue(void* data, Queue* queue) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->link = NULL;

    if(!queue->head) {
        queue->head = newNode;
        queue->tail = newNode;
        return;
    }

    Node* previous = NULL;
    Node* current = queue->head;

    while(current != NULL) {
        int cmp = queue->compare(newNode->data, current->data);

        if(queue->pType == MIN && cmp <= 0) {
            break;
        }

        if(queue->pType == MAX && cmp >= 0) {
            break;
        }

        previous = current;
        current = current->link;
    }

    if(previous == NULL) {
        newNode->link = current;
        queue->head = newNode;
    } else {
        previous->link = newNode;
        newNode->link = current;
    }

    if(newNode->link == NULL) {
        queue->tail = newNode;
    }
}

int dequeue(Queue* queue, void** data) {
    if(!queue->head) {
        printf("Queue underflow\n");
        return 0;
    }

    Node* temp = queue->head;
    *data = temp->data;
    queue->head = temp->link;

    if(queue->head == NULL) {
        queue->tail = NULL;
    }

    free(temp);
    return 1;
}

int seekHead(Queue* queue, void** data) {
    if(!queue->head) {
        printf("Queue is empty\n");
        return 0;
    }
    *data = queue->head->data;
    return 1;
}

int seekTail(Queue* queue, void** data) {
    if(!queue->tail) {
        printf("Queue is empty\n");
        return 0;
    }
    *data = queue->tail->data;
    return 1;
}

void resetQueue(Queue* queue) {
    while(queue->head) {
        Node* temp = queue->head;
        queue->head = temp->link;
        free(temp);
    }
    queue->tail = NULL;
}

void destroyQueue(Queue* queue) {
    resetQueue(queue);
    free(queue);
}
