#include <stdio.h>
#include <stdlib.h>

Stack* createStack();
void push(Stack* stack, int value);
int pop(Stack* stack);
int peek(Stack* stack);
void resetStack(Stack* stack);
void destroyStack(Stack* stack);
int isEmpty(Stack* stack);

typedef struct node {
    int value;
    Node* link;
} Node;

typedef struct stack {
    int size;
    Node* top;
} Stack;

Stack* createStack() {
    Stack* newStack = malloc(sizeof(Stack));
    newStack->top = NULL;
    newStack->size = 0;

    return newStack;
}

void push(Stack* stack, int value) {
    Node* node = malloc(sizeof(Node));
    node->value = value;
    
    node->link = stack->top;
    stack->top = node;
    stack->size++;
}

int pop(Stack* stack) {
    if(isEmpty(stack)) {
            printf("Stack Underflow\n");
            return -1;
    } else {
            Node* aux = stack->top;
            int value = aux->value;
            
            stack->top = aux->link;;
            free(aux);
            stack->size--;
            
            return value;
    }
}

int peek(Stack* stack) {
    if(isEmpty(stack)) {
            printf("Stack is empty\n");
            return -1;
    } else {
            return stack->top->value;
    }
}

void resetStack(Stack* stack) {
    while(!isEmpty(stack)) {
            pop(stack);
    }
}

void destroyStack(Stack* stack) {
    resetStack(stack);
    free(stack);
}

int isEmpty(Stack* stack) {
    if(stack->top == NULL) {
            return 1;
    } else {
            return 0;
    }
}