#include "bst.h"
#include "utils.h"

#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////

bst_node *bst_node_create(int key) {

    // initiate a node, with value 0, if no space available then leaves a
    // warning
    bst_node *node = (bst_node *)calloc(1, sizeof(bst_node));

    if (node == NULL) {
        perror("bst_node_create(): not enough space to create new node\n");
        return NULL;
    }

    node->key = key;

    return node;
}

////////////////////////////////////////////////////////////////

bst_node *bst_node_create_valued(int key, void *value, print_fn print) {

    // initiate a node, with value 0, if no space available then leaves a
    // warning
    bst_node *node = bst_node_create(key);
    node->value = value;
    node->print = print;

    return node;
}

////////////////////////////////////////////////////////////////

bst_node *bst_node_insert(bst_node *root, int key, void *value,
                          print_fn print) {
    /*
     * The function takes the root of a bst and inserts node in it.
     * If node already exists, the function does nothing and returns the root
     * without any changes
     */

    bst_node *temp = NULL;

    if (root == NULL) {
        temp = bst_node_create_valued(key, value, print);
        return temp;
    }

    if (root->key == key) {
        fprintf(stderr,
                "bst_node_insert: No duplicated node allowed to insert\n");
    }

    if (root->key > key) {
        root->left = bst_node_insert(root->left, key, value, print);
    }

    if (root->key < key) {
        root->right = bst_node_insert(root->right, key, value, print);
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

    root->print(root);
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
    root->print(root);
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
    root->print(root);
}

////////////////////////////////////////////////////////////////

void bst_display(bst_node *node, int depth) {

    // assert(sizeof(node->value) == sizeof(int));

    if (node == NULL) {
        return;
    }
    // Print right subtree first
    bst_display(node->right, depth + 1);

    // Indentation
    for (int i = 0; i < depth * 4; i++) {
        putchar(' ');
    }

    node->print(node);

    // Print left subtree
    bst_display(node->left, depth + 1);
}

////////////////////////////////////////////////////////////////

bst_node *bst_node_delete(bst_node *root, int key) {
    /*
     * deletes the node with the given value, if not in the list, then does
     * nothing
     */

    if (root == NULL) {
        perror("bst_node_delete: target node not found");
        return NULL;
    }

    bst_node *temp = NULL;

    if (root->key == key) {
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

        root->key = temp->key;
        root->value = temp->value;
        root->print = temp->print;
        root->right = bst_node_delete(root->right, temp->key);
        return root;
    }

    if (key < root->key) {
        root->left = bst_node_delete(root->left, key);
    } else {
        root->right = bst_node_delete(root->right, key);
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

bst_node *bst_search(bst_node *root, int key) {
    /*
     * finds the node with given value, return it if note in the list, return
     * NULL
     */

    if (root == NULL) {
        return NULL;
    }

    if (key < root->key) {
        return bst_search(root->left, key);
    }
    if (key > root->key) {
        return bst_search(root->right, key);
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
