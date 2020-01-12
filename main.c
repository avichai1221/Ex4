#include <stdio.h>
#include "trie.h"

int main( int argc ,char *argv[]) {

    char string[500];

    /*    char b[]="a4bce b76ac bac abc ddd aa66a";
    char b2[]="all allo aloe an ant are alot ate be allot";
    char b3[]="abc bac bac abc abc ddd aa66a";*/

   if(argc!=1)
    {
        node *root = setNull();
        while( fgets(string, 500, stdin))
        {
        //    fgets(string, 500, stdin);

        makeTrie(string, root);


        }
        printRootReverse(root);
        free(root);
        fclose(stdin);

    }
    else {
       node *root = setNull();
      // fgets(string, 500, stdin);
       while( fgets(string, 500, stdin))
       {
    //    fgets(string,500,stdin);
        makeTrie(string, root);
        //   printRoot(root);



       }
       printRoot(root);
       free(root);
       fclose(stdin);
   }

    return 0;
}
