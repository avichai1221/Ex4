#include <stdio.h>
#include "trie.h"

int main( int argc ,char *argv[])
{
  char string[1000]="ala alad aladin aa aab ";
  int length=strlen(string);
  int maxWord=0;
   node *root = setNull();
    memset(root,0, sizeof(char));
    maxWord= makeTrie(string, root,length);
   // printf("%d",maxWord);
    printRoot(root,maxWord);
printf("\n");
    printRootReverse(root,maxWord);
    freeRoot(root);

      /* while( fgets(string, INT_MAX, stdin))
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
        }*/
     //  free(root);
     //  fclose(stdin);

    return 0;
}
