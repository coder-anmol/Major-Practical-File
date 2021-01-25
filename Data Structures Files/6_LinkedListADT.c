/**
 * @author [Coder Anmol]
 * @email [dev.anmolsharma@gmail.com]
 * @desc [this program implements Linked List DataStructure]
 */
#include <stdio.h>
#include <stdlib.h>

//constructing linkedlist
typedef struct linkedList {
    int data;
    struct linkedList *next;
} node;

// function to print element inside linked list
void traverse(node *pointer) {
    int i = 0;
    while (pointer != NULL) {
        printf("Element at %d: %d\n", i, pointer->data);
        pointer = pointer->next;
        i++;
    }
}

// function to insert at first position
node *insertFirst(node *head, int data) {
    node *pointer = (node *)malloc(sizeof(node));
    pointer->data = data;
    pointer->next = head;
    return pointer;
}

// function to insert at userdefined position
node *insertAtIndex(node *head, int data, int index) {
    node *pointer     = (node *)malloc(sizeof(node));
    node *tempPointer = head;

    int i = 0;
    while (i != index - 1) {
        tempPointer = tempPointer->next;
        i++;
    }

    pointer->data     = data;
    pointer->next     = tempPointer->next;
    tempPointer->next = pointer;
    return head;
}

// function to insert at end of linked list
node *insertAtEnd(node *head, int data) {
    node *pointer = (node *)malloc(sizeof(node));
    pointer->data = data;
    pointer->next = NULL;
    node *p       = head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = pointer;
    return head;
}

// function to insert after certain element
node *insertAfter(node *head, node *previousNode, int data) {
    node *pointer = (node *)malloc(sizeof(node));
    pointer->data = data;

    pointer->next      = previousNode->next;
    previousNode->next = pointer;
    return head;
}

int main() {

    node *head, *inputNode;

    // setting default values
    head->next = NULL;
    head->data = 0;

    int input, data, index;

    // taking user input
    printf("\n\nHow many elements do you want in your linked list: ");
    scanf("%d", &input);

    if (input > 0) {
        for (int i = 0; i < input; i++) {
            printf("\nEnter value: ");
            scanf("%d", &data);
            head = insertFirst(head, data);
        }
    } else {
        printf("\nWrong value\n");
        exit(1);
    }

    // traversing linked list
    traverse(head);

    // asking user to execute operation
    printf("\nWhat operation do you want to run: \n");
    printf("\n1. Insert New Element at First");
    printf("\n2. Insert New Element at Specific Index");
    printf("\n3. Insert New Element at the end");
    printf("\n4. Insert New Element after some specific element");
    printf("\nGive your input from this [1,2,3,4] :");
    scanf("%d", &input);

    switch (input) {
        case 1:
            printf("\nEnter input value: ");
            scanf("%d", &data);
            head = insertFirst(head, data);    // inserts at first
            break;
        case 2:
            printf("\nEnter input value: ");
            scanf("%d", &data);
            printf("\nEnter index: ");
            scanf("%d", &index);
            head = insertAtIndex(head, data, index);    // inserts at specific index
            break;
        case 3:
            printf("\nEnter input value: ");
            scanf("%d", &data);
            head = insertAtEnd(head, data);    // inserts at the end
            break;
        case 4:
            printf("\nEnter input value: ");
            scanf("%d", &data);
            head = insertAfter(head, head, data);    // default set to head
            break;
        default:
            printf("\nWrong Input");    // runs if input is wrong
            break;
    }
    // again traversing to show the changes
    traverse(head);
    return 0;
}