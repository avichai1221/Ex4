#ifndef EX4_TRIE_H
#define EX4_TRIE_H
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#define NUM_LETTES 26

typedef enum {FALSE=0, TRUE=1} boolean;
typedef struct node {
    char letter;
    boolean isEndOfWord;
    long unsigned int count;
    struct node* children[NUM_LETTES];
}node;


char* notChar (char a[]);
void insert(node *root,  char *key);
node* setNull();
void makeTrie (char b[],node* root);
void printRoot (node* root);
void printNode (node* currentNode, char* str, int length);
void printRootReverse (node* root);
void printNodeReverse (node* currentNode, char* str, int length);

#endif //EX4_TRIE_H