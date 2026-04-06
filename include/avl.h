#ifndef AVL_H
#define AVL_H

#include "bst.h"
typedef struct avl_node_struct {
    int value;
    struct avl_node_struct *left;
    struct avl_node_struct *right;
    int height;
} avl_node;

typedef struct {
    avl_node *first;
    avl_node *second;
} avl_pair;

avl_node *avl_node_create(); // O(1)

avl_node *avl_node_create_valued(int value); // O(1)

// O(1), this one should be a BST function
int avl_height(avl_node *root);

// O(1), this one should be a BST function
avl_node *avl_rotation_left(avl_node *root);
// O(1), this one should be a BST function
avl_node *avl_rotation_right(avl_node *root);

avl_node *avl_node_insert(avl_node *root, int value); // O(log n)

void avl_preorder_print(avl_node *root); // O(n)

void avl_inorder_print(avl_node *root); // O(n)

void avl_postorder_print(avl_node *root); // O(n)

avl_node *avl_node_delete(avl_node *root, int value); // O(log n)

avl_node *avl_delete(avl_node *root); // O(n)

avl_node *avl_search(avl_node *root, int value); // O(log n)

avl_pair *avl_split(avl_node *root, int value);

avl_node *avl_join(avl_node *left, int value, avl_node *right); // O(log n)

avl_node *avl_union(avl_node *root1, avl_node *root2);

#endif
