#ifndef NODE_H
#define NODE_H

typedef struct node{
    int value;
    int value_two;
    char word[50];
    struct node *left;
    struct node *right;
} Tree_node;

#endif // NODE_H
