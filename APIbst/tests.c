#include "bst.h"
#include "stdio.h"
// #include "stdlib.h"

typedef struct bst_node_struct {
    char x;
} bst_node;

void temp() {

    bst_node *root = (void *)0x0;
    root = bst_node_insert(root, 3);
    root = bst_node_insert(root, -4);
    root = bst_node_insert(root, -2);
    root = bst_node_insert(root, -3);
    root = bst_node_insert(root, 2);
    root = bst_node_insert(root, 7);
    root = bst_node_insert(root, 5);
    root = bst_node_insert(root, 9);

    bst_inorder_print(root);
    printf("\n");

    root = bst_node_delete(root, 5);
    bst_inorder_print(root);
    printf("\n");

    root = bst_delete(root);
    bst_inorder_print(root);
    printf("\n");
}

int main() {

    temp();

    return 0;
}
