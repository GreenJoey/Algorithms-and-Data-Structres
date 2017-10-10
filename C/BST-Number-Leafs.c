#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>


typedef struct bst_t {
    int data;
    struct bst_t *left;
    struct bst_t *right;
} bst_t;


void append(bst_t **tree, int data) {
    if(*tree && (data > (*tree)->data))
        append(&(*tree)->right, data);
    else if(*tree && (data <= (*tree)->data))
        append(&(*tree)->left, data);
    else {
        *tree = (bst_t *)malloc(sizeof(bst_t));
        (*tree)->data = data;
        (*tree)->left = NULL;
        (*tree)->right = NULL;
    }
}


void display(bst_t *tree) {
    if(tree->right)
        display(tree->right);

    printf("%d->", tree->data);

    if(tree->left)
        display(tree->left);
}


int get_leaves(bst_t *tree) {
    int leaves = 0;

    if(tree->left == NULL && tree->right == NULL)
        return 1;

    if(tree->left)
        leaves += get_leaves(tree->left);

    if(tree->right)
        leaves += get_leaves(tree->right);

    return leaves;
}


int main() {
    bst_t *tree = NULL;
    int values[] = {45, 39, 78, 54, 79, 55, 80};

    for(int i=0; i<7; ++i)
        append(&tree, values[i]);

    display(tree);
    printf("\nNumber of Leaves: %d\n", get_leaves(tree));

    return 0;
}
