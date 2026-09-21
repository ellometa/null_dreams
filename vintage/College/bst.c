#include <stdio.h>
#include <stdlib.h>

typedef struct NodeDabba {
    int data;
    struct NodeDabba* left;
    struct NodeDabba* right;
} NodeDabba;


void preorder(NodeDabba *root) {        
    if (!root) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(NodeDabba *root) {     
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(NodeDabba *root) {         
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}


int main(void) {

    printf("Preorder:  ");
    preorder(root);
    printf("\n");

    printf("Inorder:   ");
    inorder(root);
    printf("\n");

    printf("Postorder: ");
    postorder(root);
    printf("\n");

    freeTree(root);
    return 0;
}
