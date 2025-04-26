#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int top; //index
    int size;    
    int* array;
} Stack;

Stack* createStack(int size);
void push(Stack* stack, int value);
int pop(Stack* stack);
int peek(Stack* stack);
void resetStack(Stack* stack);
int isFull(Stack* stack);
int isEmpty(Stack* stack);

Stack* createStack(int size) {
    Stack* newStack = malloc(sizeof(Stack));
    newStack->array = malloc(sizeof(int)*size);
    newStack->top = -1;
    newStack->size = size;

    return newStack;
}

void push(Stack* stack, int value) {
    if(isFull(stack)) {
            printf("Stack Overflow\n");
            return;
    } else {
            stack->top++;
            stack->array[stack->top] = value;
    }
}

int pop(Stack* stack) {
    if(isEmpty(stack)) {
            printf("Stack Underflow\n");
            return 0;
    } else {
            int value = stack->array[stack->top];
            stack->top--;
            return value;
    }
}

int peek(Stack* stack) {
    if(isEmpty(stack)) {
            printf("Stack is empty\n");
            return 0;
    } else {
            return stack->array[stack->top];
    }
}

void resetStack(Stack* stack) {
    stack->top = -1;
}

void destroyStack(Stack* stack) {
        free(stack->array);
        free(stack);
}

int isFull(Stack* stack) {
    if(stack->top == stack->size - 1) {
            return 1;
    } else {
            return 0;
    }
}

int isEmpty(Stack* stack) {
    if(stack->top == -1) {
            return 1;
    } else {
            return 0;
    }
}