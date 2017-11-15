#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#define WORD_COUNT 26



typedef struct _node {
    bool is_end;  // Marks the end of word if set to true
    struct _node *children[WORD_COUNT];
} trie_node;



void create(trie_node **node) {
    *node = (trie_node *)malloc(sizeof(trie_node));

    for(int i=0; i<WORD_COUNT; ++i)
        (*node)->children[i] = NULL;
}


void insert(trie_node *root, char *word, int len) {
    for(int i=0; i<len; ++i) {
        // Calculate the position of new node in array using ASCII code
        int pos = (int)word[i] - (int)'a';
        printf("Inserting %c\n", pos+(int)'a');

        // If a node doesn't exists in that position, add it
        if(root->children[pos] == NULL) {
            printf("Creating node for %c\n", word[i]);
            create(&root->children[pos]);
        }

        // Make the next node as the current root for traversing
        root = root->children[pos];
    }

    root->is_end = true;  // We have fully inserted the word, indicate it
}


bool search(trie_node *root, char *word, int len) {
    for(int i=0; i<len; ++i) {
        // Calculate the position of expected node using ASCII values
        int pos = (int)word[i] - (int)'a';

        // The value at the expected position shouldn't be NULL,
        // If it is, then it means that the word is not present
        if(root->children[pos] == NULL)
            return false;

        printf("Current node %c\n", pos + (int)'a');
        root = root->children[pos];  // Traverse the trie
    }

    // Since create of a node is done by setting every value
    // in the array to NULL, check if the current node is NULL
    // It shouldn't be as and the is_end indicator should be true
    return (root != NULL) && (root->is_end);
}


int main() {
    trie_node root;

    insert(&root, "hello", 5);
    insert(&root, "hi", 2);

    printf("%s\n", (search(&root, "hello", 5))?"Yes":"No");
    printf("%s\n", (search(&root, "hola", 4)?"Yes":"No"));
    

    return 0;
}
