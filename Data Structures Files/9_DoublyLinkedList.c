/**
 * @author [Coder Anmol]
 * @email [dev.anmolsharma@gmail.com]
 * @desc [this program implements doubly linked list]
 */
#include <stdio.h>
#include <stdlib.h>

/* container to store Linked list related data */
typedef struct doublyLinkedList {
    int data;
    struct doublyLinkedList *next, *prev;
} node;

// prints the node
void printNode(node *point) {
    while (point != NULL) {
        printf("%d\n", point->data);
        point = point->next;
    }
}

// inserts element
node *Insert(node *head, int data) {
    node *point = (node *)malloc(sizeof(node));
    point->data = data;
    point->next = NULL;
    node *temp  = head;
    if (head == NULL) {
        point->prev = NULL;
        head        = point;
        return NULL;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next  = point;
    point->prev = temp;
    return head;
}

// deletes the element
node *Delete(node *head) {
    node *point = head;
    node *temp  = head->next;
    while (temp->next != NULL) {
        point = point->next;
        temp  = temp->next;
    }
    point->next = NULL;
    point->prev = temp->prev;
    free(temp);
    return head;
}

int main() {
    /* nodes for Linked list */
    node *head, *second, *third;

    head   = (node *)malloc(sizeof(node));
    second = (node *)malloc(sizeof(node));
    third  = (node *)malloc(sizeof(node));

    head->data = 100;
    head->next = second;
    head->prev = NULL;

    second->data = 200;
    second->next = third;
    second->prev = head;

    third->data = 300;
    third->next = NULL;
    third->prev = second;

    printf("Before The Insertion\n");
    printNode(head);

    printf("\n\n");

    head = Insert(head, 400);

    printf("After the Insertion\n");
    printNode(head);

    printf("\n\n");

    third = Delete(head);    // deleting the head
    printf("After the Deletion\n");
    printNode(head);

    printf("\n\n");

    return 0;
}
