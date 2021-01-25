/**
 * @author [Coder Anmol]
 * @email [dev.anmolsharma@gmail.com]
 * @desc [this program implements Deletion in Linked List]
 */
#include <stdio.h>
#include <stdlib.h>

//linked list basic structure
typedef struct linkedList {
    int data;
    struct linkedList *next;
} node;

// prints elements in the linked list
void traverse(node *pointer) {
    while (pointer != NULL) {
        printf("Element: %d\n", pointer->data);
        pointer = pointer->next;
    }
}

// for deleting first element of the linked list
node *deleteFirst(node *head) {
    node *pointer = head;
    head          = head->next;
    free(pointer);
    return head;
}

// for deleting  element at a given index from the linked list
node *deleteAtIndex(node *head, int index) {
    node *pointer = head;
    node *q       = head->next;
    for (int i = 0; i < index - 1; i++) {
        pointer = pointer->next;
        q       = q->next;
    }
    pointer->next = q->next;
    free(q);
    return head;
}

// for deleting  element with a given value from the linked list
node *deleteNodeWithValue(node *head, int value) {
    node *pointer = head;
    node *q       = head->next;
    while (q->data != value && q->next != NULL) {
        pointer = pointer->next;
        q       = q->next;
    }
    if (q->data == value) {
        pointer->next = q->next;
        free(q);
    }
    return head;
}

// for deleting last node of the linked list
node *deleteLast(node *head) {
    node *pointer = head;
    node *q       = head->next;
    while (q->next != NULL) {
        pointer = pointer->next;
        q       = q->next;
    }
    pointer->next = NULL;
    free(q);
    return head;
}
int main() {

    node *head, *n1, *n2, *n3, *n4, *n5;
    // creating nodes
    head = (node *)malloc(sizeof(node));
    n1   = (node *)malloc(sizeof(node));
    n2   = (node *)malloc(sizeof(node));
    n3   = (node *)malloc(sizeof(node));
    n4   = (node *)malloc(sizeof(node));
    n5   = (node *)malloc(sizeof(node));

    // assigning values to the node
    head->data = 100;
    head->next = n1;

    n1->data = 1;
    n1->next = n2;

    n2->data = 2;
    n2->next = n3;

    n3->data = 3;
    n3->next = n4;

    n4->data = 4;
    n4->next = n5;

    n5->data = 5;
    n5->next = NULL;
    //  traversing for first time
    traverse(head);

    printf("\nDeleting the head of linked list: \n");
    head = deleteFirst(head);    // deleting head of linked list

    traverse(head);    // showing updated linked list

    printf("\nDeleting the last node of linked list: \n");
    head = deleteLast(head);    // deleting last element of linked list

    traverse(head);    // showing updated linked list

    printf("\nDeleting the node with a value: \n");
    head = deleteNodeWithValue(head, 2);    // deleting a node with the specific value

    traverse(head);    // showing updated linked list

    return 0;
}