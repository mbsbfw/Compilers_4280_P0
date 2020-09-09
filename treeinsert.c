#include "tree.h"
#include "node.h"
#include <stdlib.h>
#include <string.h>

static Tree_node *Tree_node_construct(int val, int val_two, char str[]){

    Tree_node *tn;
    tn = malloc(sizeof(Tree_node));
    tn -> left = NULL;
    tn -> right = NULL;
    tn -> value = val;
    tn -> value_two = val_two;
    strncpy (tn->word, str, sizeof(tn->word));
    return tn;
}

Tree_node *Tree_insert(Tree_node *tn, int val, int val_two, char str[]){
    //printf("%d\n", val_two);

    if(tn == NULL){

        return Tree_node_construct(val, val_two, str);
    }

    if(val == (tn -> value)){

        if(val_two == (tn -> value_two)){

            strncat(tn->word, ", ", sizeof(tn->word));
            strncat(tn->word, str, sizeof(tn->word));
            return tn;
        }

        if(val_two < (tn -> value_two)){

            tn -> left = Tree_insert(tn -> left, val, val_two, str);
        }

        else{

            tn -> right = Tree_insert(tn -> right, val, val_two, str);
        }
        return tn;
    }

    if(val < (tn -> value)){

        tn -> left = Tree_insert(tn -> left, val, val_two, str);
    }

    else{

        tn -> right = Tree_insert(tn -> right, val, val_two, str);
    }

    return tn;
}
