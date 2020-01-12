#include <stdio.h>
#include "trie.h"

int main( int argc ,char *argv[])
{

    char string[500];
    node *root = setNull();

    while( fgets(string, 500, stdin))
    {
        makeTrie(string, root);
    }
   if(argc!=1)
    {
        printRootReverse(root);
    }
    else
     {
         printRoot(root);
     }
    //free(root);
    fclose(stdin);

    return 0;
}
