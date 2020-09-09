#ifndef TREE_H
#define TREE_H
#include "node.h"
#include <stdio.h>

Tree_node *build_tree(FILE *f);

Tree_node *Tree_insert(Tree_node *root, int v, int val_two, char str[]);

void Tree_print(Tree_node * root, int level, char str[]);

#endif // TREE_H

