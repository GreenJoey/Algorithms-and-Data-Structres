/**
  * Finding the Lowest Common Ancestor of two node in a Binary Search Tree
**/
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>


typedef struct _t {
    int data;
    struct _t *left;
    struct _t *right;
} tree;


tree *lca(tree *root, int key1, int key2) {
    if(root == NULL)
        return NULL;

    if(root->data > key1 && root->data > key2)
        return lca(root->left, key1, key2);
    
    else if(root->data < key1 && root->data < key2)
        return lca(root->right, key1, key2);
    else
        return root;
}


void append(tree **root, int data) {
    if(*root == NULL) {
        *root = (tree *)malloc(sizeof(tree));
        (*root)->data = data;
        (*root)->left = NULL;
        (*root)->right = NULL;
        return;
    }

    if((*root)->data > data)
        append(&(*root)->left, data);
    else
        append(&(*root)->right, data);
}


int main() {
    tree *root = NULL;
    append(&root, 20);
    append(&root, 8);
    append(&root, 22);
    append(&root, 4);
    append(&root, 12);
    append(&root, 10);
    append(&root, 14);

    printf("LCA of 10 and 14: %d\n", lca(root, 10, 14)->data);
    printf("LCA of 14 and 8: %d\n", lca(root, 14, 8)->data);
    printf("LCA of 10 and 22: %d\n", lca(root, 10, 22)->data);
    return 0;
}
