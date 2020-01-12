#include <stdio.h>
#include "trie.h"

int main( int argc ,char *argv[])
{

  char string[INT_MAX];
    node *root = setNull();
    makeTrie(string, root);

       while( fgets(string, INT_MAX, stdin))
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
       free(root);
       fclose(stdin);

    return 0;
}
