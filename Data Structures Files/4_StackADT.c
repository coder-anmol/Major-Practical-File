/**
 * @author [Coder Anmol]
 * @email [dev.anmolsharma@gmail.com]
 * @desc [this program implements Stack Data Structure]
 */

#include <stdio.h>
#include <stdlib.h>

// Stack Construction using array
typedef struct stack {
    int *arr;
    int top;
    int size;
} Stack;

// Checks is the given stack is empty or not
int isEmpty(Stack *ptr) {
    if (ptr->top == -1)
        return 1;
    else
        return 0;
}

// Checks is the given stack is full or not
int isFull(Stack *ptr) {
    if (ptr->top == ptr->size - 1)
        return 1;
    else
        return 0;
}

// Push Function
void push(Stack *ptr, int value) {
    if (isFull(ptr)) {
        printf("Stack Overflow \n");
    } else {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

// Pop Function
int pop(Stack *ptr) {
    if (isEmpty(ptr)) {
        printf("Stack Underflow \n");
        return -1;    // Assuming that -1 is not present in our stack
    } else {
        int value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}

int main(void) {
    int val;
    Stack *sp = (Stack *)malloc(sizeof(Stack));    // sp is a stack pointer
    sp->top   = -1;                                // Stack is empty.

    printf("\n\nEnter the size of your stack: ");
    scanf("%d", &sp->size);                             // Size of stack taken by user.
    sp->arr = (int *)malloc(sp->size * sizeof(int));    // creating stack in heap memory.

    // checking if our stack is empty
    if (isEmpty(sp)) {
        printf("\nYour stack is empty Fill It Now\n");
    }

    // Taking values from user
    for (int i = 0; i < sp->size; i++) {
        printf("Enter value:");
        scanf("%d", &val);
        push(sp, val);
    }

    // checking stack is full or not
    if (isFull(sp)) {
        printf("\nYour stack is full Now\n");
    }

    printf("\nHow many elements do you want to remove from your stack:");
    scanf("%d", &val);    // user input to remove elements

    // popping elements from the stack
    for (int i = 0, t = sp->top; i < val; i++, t--) {
        printf("\nThe element at position %d with value: %d is popped", t + 1, pop(sp));
    }

    // checking if the stack is empty
    if (isEmpty(sp)) {
        printf("\nYour stack is empty now");
    }

    // printing leftover elements in the stack
    printf("\n\nRemaining elements in stack:");
    for (int i = sp->top; i >= 0; i--) {
        printf("\nElement at position %d is: %d", i + 1, sp->arr[i]);
    }
    printf("\n\n\n");
    return 0;
}
