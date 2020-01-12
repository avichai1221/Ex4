#include <stdio.h>
#include "trie.h"
/*
 * Reads the input and puts every word in the tree
 */
void makeTrie (char b[],node* root)
{
    char* help;
    help= (char*)malloc(sizeof(char)*strlen(b));
    if(help==NULL)
    {
        printf("error\n");
        exit(1);
    }
    int i=0;
    for (int start=0; start < strlen(b); start++)
    {
        if (b[start] != ' ') {
            help[i++] = b[start];

        } else {
            help[i] = '\0';
            char *h = notChar(help);
            insert(root, h);
            free(h);
            i = 0;
        }
        if (start == strlen(b) - 1)
        {
        help[i] = '\0';
        char *h = notChar(help);
        insert(root, h);
        free(h);
    }
    }

    free(help);
}





/*
 * this function check if we have chars that they no in a"b.
 * if we have the function remove them.
 * if we have a big char the function change it to small char.
 */
char* notChar (char a[])
{
    char* help;
    int j=0;
    help= (char*)malloc(sizeof(char));
    if(help==NULL)
    {
        printf("error\n");
        exit(1);
    }
    for (int i = 0; a[i] !='\0' ; i++)
    {
        if (a[i] >= 'A' && a[i] <= 'Z')
        {
           help= realloc(help,strlen(help)+sizeof(char));
            if(help==NULL)
            {
                printf("error\n");
                exit(1);
            }
            help[j++] = a[i] - 'A' + 'a';
        }
        if (a[i] >= 'a' && a[i] <= 'z')
        {
           help= realloc(help,sizeof(char)+strlen(help));

            if(help==NULL)
            {
                printf("error\n");
                exit(1);
            }
            help[j++] = a[i];
        }
    }
    return help;
}


/*
 * Returns first node-head
 * set null's
 */
node* setNull()
{
    node* head = NULL;

    head =(node*)malloc(sizeof(node));

    if (head!=NULL)
    {
        head->isEndOfWord = FALSE;
        head->count=0;

        for (int i = 0; i < NUM_LETTES; i++)
            head->children[i] = NULL;
    }

    return head;
}



/*If not present, inserts
 * If the key is prefix of trie node, just marks leaf node
 * update the counter if the word exist
 */
void insert(node* root,char *key)
{
    int index;
    node* help = root;
    for (int i = 0; i < strlen(key); i++)
    {
        index = ((int)key[i] - (int)'a');
        if (!help->children[index])
        {

            help->children[index] =setNull();
            help->children[index]->letter=key[i];
        }
        help = help->children[index];
    }


    // mark the last node true (end word)
    help->isEndOfWord = TRUE;
    help->count++;
    free(root);
}

void printRoot (node* root)
{
    for (int i = 0; i < NUM_LETTES; i++)
    {
        if (root->children[i] != NULL)
        {
            char* str =(char*)malloc(sizeof(char));
            printNode(root->children[i], str, 0);
        //    free(str);
        }
    }
}

void printNode (node* currentNode, char* str, int length)
{

    str[length] = currentNode->letter;
    str[length+1] = '\0';

    if(currentNode->isEndOfWord)
    {
        printf("%s", str);
        printf("\t%ld\n", currentNode->count);
    }
    for( int i = 0; i < NUM_LETTES; i++)
    {
        if (currentNode->children[i] != NULL)
        {
            str= (char*)realloc(str,strlen(str)+sizeof(char));
            printNode(currentNode->children[i], str, length+1);
        }

    }
    free(str);
}


void printRootReverse (node* root)
{


    for (int i = NUM_LETTES; i >=0; i--)
    {
        if (root->children[i] != NULL)
        {
            char* str =(char*)malloc(sizeof(char));
            printNodeReverse(root->children[i], str, 0);
            free(str);
        }
    }
}

void printNodeReverse (node* currentNode, char* str, int length)
{
    str[length] = currentNode->letter;
    str[length + 1] = '\0';

    for (int i = NUM_LETTES; i >= 0; i--)
    {
        if (currentNode->children[i] != NULL)
        {
            str = (char *) realloc(str, strlen(str) + sizeof(char));
            printNodeReverse(currentNode->children[i], str, length + 1);
        }

    }
    if (currentNode->isEndOfWord)
    {
        str[length+1] = '\0';
        printf("%s", str);
        printf("\t%ld\n", currentNode->count);
    }
    free(str);

}
