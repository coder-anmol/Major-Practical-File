/**
 * @author [Coder Anmol]
 * @email [dev.anmolsharma@gmail.com]
 * @desc [this program implements Queue DataStructure]
 */
#include <stdio.h>
#include <stdlib.h>

// construction of Queue using array
typedef struct queueADT {
    int *arr;
    int size;
    int rear;
    int front;
} Queue;

// function to check if Queue is empty
int isEmpty(Queue *ptr) {
    if (ptr->rear == ptr->front) {
        return 1;
    }
    return 0;
}

// function to check if Queue is full
int isFull(Queue *ptr) {
    if (ptr->rear == ptr->size - 1) {
        return 1;
    }
    return 0;
}

// function to enqueue element inside Queue
void enqueue(Queue *ptr, int value) {
    if (isFull(ptr)) {
        printf("Your queue is full\n");
    } else {
        ptr->rear++;
        ptr->arr[ptr->rear] = value;
    }
}

// function to dequeuw element from Queue
int dequeue(Queue *ptr) {
    int val = -1;
    if (isEmpty(ptr)) {
        printf("Your queue is empty\n");
    } else {
        ptr->front++;
        val = ptr->arr[ptr->front];
    }
    return val;
}

// main function
int main(void) {
    Queue *students = (Queue *)malloc(sizeof(Queue));
    int input;
    students->front = students->rear = -1;

    printf("\n\nEnter the size of your queue: ");
    scanf("%d", &students->size);

    students->arr = (int *)malloc(students->size * sizeof(int));

    printf("Please fill your queue: \n");
    // taking input inside queue
    for (int i = 0; i < students->size; i++) {
        printf("Enter element: ");
        scanf("%d", &input);
        enqueue(students, input);
    }

    // printing queue after adding elements inside it
    printf("\nYour Queue after adding elements into it: \n");
    for (int i = students->front + 1; i <= students->rear; i++) {
        printf("Element at postion: %d is: %d\n", i + 1, students->arr[i]);
    }

    // taking user input to remove elements inside queue
    printf("\nHow many elements you want to remove in your queue: ");
    scanf("%d", &input);

    // removing elements
    for (int i = 0; i < input; i++) {
        printf("Removing the element at position: %d with value: %d\n", i + 1, dequeue(students));
    }

    // printing leftover elements
    printf("\nLeftover elements in your queue: \n");
    for (int i = students->front + 1, j = 1; i <= students->rear; i++, j++) {
        printf("Element at postion: %d is: %d\n", j, students->arr[i]);
    }

    printf("\n\n");
    return 0;
}
