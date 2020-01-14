#include <stdio.h>
#include "trie.h"

int main( int argc ,char *argv[])
{
  char string[1000]="aa aaa aaaa";
  int length=strlen(string);
  int maxWord=0;
   node *root = setNull();
   memset(root,0, sizeof(char));



       while(fgets(string, 1000, stdin))
       {
           maxWord= makeTrie(string, root,length);
       }
      if(argc!=1)
       {
           printRootReverse(root,maxWord);
       }
       else
        {
           printRoot(root,maxWord);
        }
      freeRoot(root);
      fclose(stdin);

    return 0;
}
