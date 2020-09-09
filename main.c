#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "tree.h"

int main(int argc, char *argv[]){
    Tree_node *root = NULL;
    char str[100];
    char out_file[] = "out";
    int level = 0;

    //Declare file pointer
    FILE *f_pointer;

    /*
        If command line arguments equal one then we will create a new file
        if the file does not exist. Then it allows for standard input from
        the user to fill that file
    */
    if(argc == 1){
		  
        FILE *fo_pointer = fopen(out_file, "w");

        if(fo_pointer == NULL) {
            perror("Error: ");
            return(-1);
        }

        while(1){
            fgets(str, sizeof(str), stdin);
            if (strcmp(str, "EOF\n") == 0 || strcmp(str, "eof\n") == 0
                || strcmp(str, "EOF") == 0 || strcmp(str, "eof") == 0){
                printf("Breaking...\n");
                break;
            }
            else
                fprintf(fo_pointer, str);

        }//end while

        fclose(fo_pointer);
        f_pointer = fopen(out_file, "r");
    }//end if(argc==1)

    /*
        ELSE IF command line arguments equals two we open the file that
        the user entered with ./PO [file]
    */
    else if(argc == 2){

        f_pointer = fopen(argv[1], "r");

        if(f_pointer == NULL){
            perror("ERROR: ");
            exit(-1);
        }
    }//end if(argc==2)

    else if(argc > 2){
        printf("ERROR: Too many arguments");
        exit(-1);
    }

    root = build_tree(f_pointer);
    Tree_print(root, level, out_file);
    fclose(f_pointer);

    return 0;
}
