#include "bst.h"
#include "utils.h"

#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////

bst_node *bst_node_create() {

    // initiate a node, with value 0, if no space available then leaves a
    // warning
    bst_node *node = (bst_node *)calloc(1, sizeof(bst_node));

    if (node == NULL) {
        printf("bst_node_create(): not enough space to create new node\n");
    }

    return node;
}

////////////////////////////////////////////////////////////////

bst_node *bst_node_create_valued(int value) {

    // initiate a node, with value 0, if no space available then leaves a
    // warning
    bst_node *node = (bst_node *)calloc(1, sizeof(bst_node));

    if (node == NULL) {
        printf("bst_node_create(): not enough space to create new node\n");
    }
    node->value = value;

    return node;
}

////////////////////////////////////////////////////////////////

bst_node *bst_node_insert(bst_node *root, int value) {
    /*
     * The function takes the root of a bst and inserts node in it.
     * If node already exists, the function does nothing and returns the root
     * without any changes
     */

    bst_node *temp = NULL;

    if (root == NULL) {
        temp = bst_node_create_valued(value);
        return temp;
    }

    if (root->value == value) {
        printf("bst_node_insert: No duplicated node allowed to insert\n");
    }

    if (root->value > value) {
        root->left = bst_node_insert(root->left, value);
    }

    if (root->value < value) {
        root->right = bst_node_insert(root->right, value);
    }

    return root;
}

////////////////////////////////////////////////////////////////

void bst_preorder_print(bst_node *root) {

    /*
     * Print the input bst using preorder traversal
     */

    if (root == NULL) {
        return;
    }

    printf("%d ", root->value);
    bst_preorder_print(root->left);
    bst_preorder_print(root->right);
}

////////////////////////////////////////////////////////////////

void bst_inorder_print(bst_node *root) {
    /*
     * Print the input bst using inorder traversal (smallest to greatest)
     */

    if (root == NULL) {
        return;
    }

    bst_inorder_print(root->left);
    printf("%d ", root->value);
    bst_inorder_print(root->right);
}

////////////////////////////////////////////////////////////////

void bst_postorder_print(bst_node *root) {
    /*
     * Print the input bst using postorder traversal
     */

    if (root == NULL) {
        return;
    }

    bst_postorder_print(root->left);
    bst_postorder_print(root->right);
    printf("%d ", root->value);
}

////////////////////////////////////////////////////////////////

void bst_display(bst_node *node, int depth) {
    if (node == NULL)
        return;

    // Print right subtree first
    bst_display(node->right, depth + 1);

    // Indentation
    for (int i = 0; i < depth * 4; i++) {
        putchar(' ');
    }

    printf("%d\n", node->value);

    // Print left subtree
    bst_display(node->left, depth + 1);
}

////////////////////////////////////////////////////////////////

bst_node *bst_node_delete(bst_node *root, int value) {
    /*
     * deletes the node with the given value, if not in the list, then does
     * nothing
     */

    if (root == NULL) {
        printf("bst_node_delete: target node not found");
        return NULL;
    }

    bst_node *temp = NULL;

    if (root->value == value) {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        if (root->left == NULL) {
            temp = root;
            root = root->right;
            free(temp);
            return root;
        }

        if (root->right == NULL) {
            temp = root;
            root = root->left;
            free(temp);
            return root;
        }

        temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }

        root->value = temp->value;
        root->right = bst_node_delete(root->right, temp->value);
        return root;
    }

    if (value < root->value) {
        root->left = bst_node_delete(root->left, value);
    } else {
        root->right = bst_node_delete(root->right, value);
    }

    return root;
}

////////////////////////////////////////////////////////////////

bst_node *bst_delete(bst_node *root) {
    /*
     * Delete the entire bst, and return the position of the (already
     * deallocated) input address
     *
     * (done through postorder traversal)
     */

    if (root == NULL) {
        return NULL;
    }
    root->left = bst_delete(root->left);
    root->right = bst_delete(root->right);

    free(root);
    return NULL;
}

////////////////////////////////////////////////////////////////

bst_node *bst_search(bst_node *root, int value) {
    /*
     * finds the node with given value, return it if note in the list, return
     * NULL
     */

    if (root == NULL) {
        return NULL;
    }

    if (value < root->value) {
        return bst_search(root->left, value);
    }
    if (value > root->value) {
        return bst_search(root->right, value);
    }

    return root;
}

////////////////////////////////////////////////////////////////

int bst_height(bst_node *root) {

    if (root == NULL) {
        return 0;
    }

    int height_left = bst_height(root->left);
    int height_right = bst_height(root->right);

    return ds_max(height_left, height_right) + 1;
}
