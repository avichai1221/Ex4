#include <stdio.h>
#include "trie.h"

int main( int argc ,char *argv[]) {

    char string[500];

    /*    char b[]="a4bce b76ac bac abc ddd aa66a";
    char b2[]="all allo aloe an ant are alot ate be allot";
    char b3[]="abc bac bac abc abc ddd aa66a";*/

   if(argc==1)
    {

fgets(string, 500, stdin);
    node *root = setNull();
    makeTrie(string, root);
    printRootReverse(root);
    free(root);
    }
    else {
       fgets(string, 500, stdin);
       node *root = setNull();
       makeTrie(string, root);
       printRoot(root);
       free(root);


   }

    return 0;
}
