/**
 * @author [Coder Anmol]
 * @email [dev.anmolsharma@gmail.com]
 * @desc [this program implements Circular Linked List]
 */
#include <stdio.h>
#include <stdlib.h>
// constructing circular linked list
typedef struct circularLinkedList {
    int data;
    struct circularLinkedList *next;
} node;

//  function to traverse
void traverse(node *head) {
    node *pointer = head;
    do {
        printf("Element is : %d\n", pointer->data);
        pointer = pointer->next;
    } while (pointer != head);
}

//  function to insert element at first
node *insertAtFirst(node *head, int data) {
    node *pointer = (node *)malloc(sizeof(node));
    pointer->data = data;
    node *p       = head->next;
    while (p->next != head) {
        p = p->next;
    }
    // at this point p is pointing to the last node of the circular linked list
    p->next       = pointer;
    pointer->next = head;
    head          = pointer;
    return head;
}

int main() {
    node *head, *first, *second, *last;

    head   = (node *)malloc(sizeof(node));
    first  = (node *)malloc(sizeof(node));
    second = (node *)malloc(sizeof(node));
    last   = (node *)malloc(sizeof(node));

    head->data = 100;
    head->next = first;

    first->data = 1;
    first->next = second;

    second->data = 2;
    second->next = last;

    last->data = 3;
    last->next = head;    // pointing to the head again thus creating a  circular linked list

    printf("\n\n");
    // showing elements of circular linked list
    traverse(head);

    printf("\nInserting element at first: \n");
    head = insertAtFirst(head, 20);    // inserting at first index
    traverse(head);                    // showing update in the circular linked list

    printf("\n\n");
    return 0;
}