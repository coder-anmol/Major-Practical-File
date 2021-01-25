/**
 * @author [Coder Anmol]
 * @email [dev.anmolsharma@gmail.com]
 * @desc [this program implements Binary Tree in pre order]
 */
#include <malloc.h>
#include <stdio.h>

// creating binary tree
typedef struct BinaryTreePreorder {
    int data;
    struct BinaryTreePreorder *left, *right;
} tree;

// function to create new tree
tree *createTree(int data) {
    tree *newTree = (tree *)malloc(sizeof(tree));
    newTree->data  = data;
    newTree->left  = NULL;
    newTree->right = NULL;
    return newTree;
}

// function for pre Order Traversal of Binary Tree
void preOrderTraversal(tree *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

int main(void) {
    tree *n, *n1, *n2, *n3, *n4;

    n  = createTree(100);
    n1 = createTree(200);
    n2 = createTree(300);
    n3 = createTree(400);
    n4 = createTree(500);

    n->left   = n1;

    n->right  = n2;

    n1->left  = n3;

    n1->right = n4;

    printf("\n\n");

    preOrderTraversal(n);

    printf("\n\n");

    return 0;
}
