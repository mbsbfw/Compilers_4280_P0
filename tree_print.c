#include "node.h"
#include "tree.h"
#include <string.h>

//static int level = 0;

static void Tree_node_print(Tree_node *tn, int level, FILE *point){

    //Print to screen and print to appropriate FILE
    printf("%*c%d:%s\n", level*2, ' ', level, tn -> word);
    fprintf(point, "%*c%d:%s\n", level*2, ' ', level, tn -> word);
}
static void Tree_print_preorder(Tree_node *tn, int level, FILE *point){

    if(tn == NULL){
        return;
    }

    Tree_node_print(tn, level++, point);
    Tree_print_preorder(tn -> left, level++, point);
    level--;
    Tree_print_preorder(tn -> right, level++, point);
}

static void Tree_print_inorder(Tree_node *tn, int level, FILE *point){

    if(tn == NULL){
        return;
    }

    level++;
    Tree_print_inorder(tn -> left, level--, point);
    Tree_node_print(tn, level++, point);
    Tree_print_inorder(tn -> right, level--, point);
}

static void Tree_print_postorder(Tree_node *tn, int level, FILE *point){

    if(tn == NULL){
        return;
    }

    level++;
    Tree_print_postorder(tn -> left, level, point);
    Tree_print_postorder(tn -> right, level--, point);
    Tree_node_print(tn, level--, point);
}

void Tree_print(Tree_node *tn, int level, char str[]){

    char pre[20] = "output.preorder";
    char in[20] = "output.inorder";
    char post[20] = "output.postorder";

    //Declare pre FILE pointer open and close when finished writing to file
    printf("\n\n=====Print Preorder=====\n");
    FILE *pre_point = fopen(pre, "w");
    fprintf(pre_point, "=====Print Preorder=====\n");
    Tree_print_preorder(tn, level, pre_point);
    fclose(pre_point);

    //Declare in FILE pointer open and close when finished writing to file
    printf("\n\n=====Print Inorder=====\n");
    FILE *in_point = fopen(in, "w");
    fprintf(in_point, "=====Print Inorder=====\n");
    Tree_print_inorder(tn, level, in_point);
    fclose(in_point);

    //Declare post FILE pointer open and close when finished writing to file
    printf("\n\n=====Print Postorder=====\n");
    FILE *post_point = fopen(post, "w");
    fprintf(post_point, "=====Print Postorder=====\n");
    Tree_print_postorder(tn, level, post_point);
    fclose(post_point);

}
