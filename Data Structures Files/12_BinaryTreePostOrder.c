/**
 * @author [Coder Anmol]
 * @email [dev.anmolsharma@gmail.com]
 * @desc [this program implements Binary Tree in Post Order]
 */
#include <malloc.h>
#include <stdio.h>

// conion of binary tree
typedef struct BinaryTreePostOrder {
    int data;
    struct BinaryTreePostOrder *left, *right;
} tree;

/* Takes 1 argument (data) of type int
   takes the data, creates a new tree adds data to new tree */
tree *createTree(int data) {
    tree *newTree = (tree *)malloc(sizeof(tree));
    newTree->data  = data;
    newTree->left  = NULL;
    newTree->right = NULL;
    return newTree;
}

/* Takes 1 argument (root) of type tree
   prints values of trees in Binary Tree */
void postOrderTraversal(tree *root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}
int main() {
    tree *n, *n1, *n2, *n3, *n4;

    n  = createTree(1);
    n1 = createTree(2);
    n2 = createTree(3);
    n3 = createTree(4);
    n4 = createTree(5);

    n->left   = n1;
    n->right  = n2;
    n1->left  = n3;
    n1->right = n4;

    printf("\n\n");

    postOrderTraversal(n);

    printf("\n\n");

    return 0;
}
