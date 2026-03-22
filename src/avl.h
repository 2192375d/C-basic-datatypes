#ifndef AVL_H
#define AVL_H

#include "bst.h"
typedef struct avl_node_struct {
    int value;
    struct avl_node_struct *left;
    struct avl_node_struct *right;
    int height;
} avl_node;

avl_node *avl_node_create();

avl_node *avl_node_create_valued(int value);

int avl_height(avl_node *root);

avl_node *avl_rotation_left(avl_node *root);
avl_node *avl_rotation_right(avl_node *root);

avl_node *avl_node_insert(avl_node *root, int value);

void avl_preorder_print(avl_node *root);

void avl_inorder_print(avl_node *root);

void avl_postorder_print(avl_node *root);

avl_node *avl_node_delete(avl_node *root, int value);

avl_node *avl_delete(avl_node *root);

avl_node *avl_search(avl_node *root, int value);

#endif
