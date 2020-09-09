#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "tree.h"

Tree_node *build_tree(FILE *f_pointer){
    Tree_node *root = NULL;
    char str[15];

    /*
        While loop to scan through file word by word and insert
        into tree. Along with the word Ive sent the first and second
        letter of each word to compare with other words.
    */
    while(1){
        fscanf(f_pointer, "%s", str);

			//Break when end of file is reached
		  if(feof(f_pointer)){
		  		break;
		  }

        int first_letter = (int)(str[0]);
        int sec_letter = (int)(str[1]);
        printf("Insert %d: %s\n", first_letter, str);
        root = Tree_insert(root, first_letter, sec_letter, str);

    }// end while
    return root;
};


