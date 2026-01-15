// bst.h

/*
 * This file takes part of Lumiere's datatype libraries in C
 * The current file contains the API documentation of all functions from the
 * bst library
 *
 * Note that the bsts here take only works with integer
 *
 * No further documentation is provided in this file because the purpose of each
 * functions are self explainatory from their name
 */

#ifndef BST_H
#define BST_H

#include "linkedList.h"
typedef struct bst_node_struct {
    int value;
    struct bst_node_struct *left;
    struct bst_node_struct *right;
} bst_node;

bst_node *bst_node_create();

bst_node *bst_node_create_valued(int value);

bst_node *bst_node_insert(bst_node *root, int value);

void bst_preorder_print(bst_node *root);

void bst_inorder_print(bst_node *root);

void bst_postorder_print(bst_node *root);

bst_node *bst_node_delete(bst_node *root, int value);

bst_node *bst_delete(bst_node *root);

bst_node *bst_search(bst_node *root, int value);

// those two are still work in progress
linked_list_node *bst_to_sorted_linked_list(bst_node *root,
                                            linked_list_node *head);

bst_node *bst_get_balanced_bst(bst_node *root);
#endif
