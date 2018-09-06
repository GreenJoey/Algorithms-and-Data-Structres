#include <stdio.h>
#include <malloc.h>


typedef struct _t {
    int data;
    struct _t *left;
    struct _t *right;
} tree;


void append (tree **root, int data) {
    if (*root == NULL) {
        *root = (tree *) malloc( sizeof(struct _t) );
        (*root)->data = data;
        (*root)->left = NULL;
        (*root)->right = NULL;
        return;
    }

    if (data < (*root)->data)
        append(&(*root)->left, data);
    else
        append(&(*root)->right, data);
}


int traverse(tree *root) {
    /**
     * Traverse the tree recursively and keep the sum
     * If the a NULL value is passed then return the value of the node as 0
    **/
    if (root == NULL)
        return 0;
 
    return traverse(root->left) + root->data + traverse(root->right);
}


int sum(tree *root, int key) {
    /**
     * Calculate the total sum first.
     * Then iteratively try and find the required the node in the node, keeping track of the parent as a seperate pointer.
     *
     * When found, subtract the parent node's value from the total sum then subtract the values of left and right child's values, if they exist
     **/
    int sum = traverse(root);
    tree *parent = NULL;

    while (root) {
        if (root->data > key) {
            parent = root;
            root = root->left;
        }
        else if (root->data < key) {
            parent = root;
            root = root->right;
        }

        else {
            if (parent)
                // The `if` is to handle the special case when the key is the root node of the tree
                sum -= parent->data;

            if (root->left)
                sum -= root->left->data;
            if (root->right)
                sum -= root->right->data;
            break;
        }
    }

    return sum;
}


int main() {
    tree *root = NULL;

    append(&root, 15);
    append(&root, 13);
    append(&root, 12);
    append(&root, 14);
    append(&root, 11);
    append(&root, 20);
    append(&root, 18);
    append(&root, 24);
    append(&root, 23);
    append(&root, 25);

    printf("Sum is: %d (Key is in the middle of the tree)\n", sum(root, 20));  // When the key is in the tree
    printf("Sum is: %d (Key is the root of the tree)\n", sum(root, 15));  // When the key is the root
    printf("Sum is: %d (Key is not present in the tree)\n", sum(root, 10));  // When the key is not in the tree

    return 0;
}
