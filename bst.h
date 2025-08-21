#ifndef BST_H
#define BST_H

typedef struct bst_node_struct bst_node;

bst_node *bst_node_create();

bst_node *bst_node_create_valued(int value);

bst_node *bst_node_insert(bst_node *root, int value);

void bst_preorder_print(bst_node *root);

void bst_inorder_print(bst_node *root);

void bst_postorder_print(bst_node *root);

bst_node *bst_node_delete(bst_node *root, int value);

bst_node *bst_delete(bst_node *root);

bst_node *bst_search(bst_node *head, int value);

#endif
