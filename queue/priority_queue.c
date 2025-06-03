#include <stdio.h>
#include <stdlib.h>

// regra de comparacao fixa (um tipo de dado)

typedef enum {
    MIN = -1,
    MAX = 1
} PRIORITY_TYPE;

typedef struct node {
    int value;
    struct node* link;
} Node;

typedef struct queue {
    Node* head;
    Node* tail;
    PRIORITY_TYPE pType;
} Queue;

Queue* createQueue(PRIORITY_TYPE pType) {
    Queue* newQueue = malloc(sizeof(Queue));
    newQueue->head = NULL;
    newQueue->tail = NULL;
    newQueue->pType = pType;

    return newQueue;
}

void enqueue(int value, Queue* queue) {
    Node* newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->link = NULL;

    if(!queue->head) {
        queue->head = newNode;
        queue->tail = newNode;
        return;
    }

    Node* previous = NULL;
    Node* current = queue->head;

    while(current != NULL) {

        if(queue->pType == -1 && newNode->value <= current->value) {
            break;
        }

        if(queue->pType == 1 && newNode->value >= current->value) {
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

int dequeue(Queue* queue, int* value) {
    if(!queue->head) {
        printf("Queue underflow\n");
        return 0;
    }

    Node* temp = queue->head;
    *value = temp->value;
    queue->head = temp->link;

    if(!queue->head == NULL) {
        queue->tail = NULL;
    }

    free(temp);
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
        queue->head = temp->link;
        free(temp);
    }
    queue->tail = NULL;
}

void destroyQueue(Queue* queue) {
    resetQueue(queue);
    free(queue);
}
