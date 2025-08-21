#include "bst.h"
#include "stdio.h"
#include "stdlib.h"

typedef struct bst_node_struct {
    int value;
    struct bst_node_struct *left;
    struct bst_node_struct *right;
} bst_node;

// initiate a node, with value 0, if no space available then print stuff
bst_node *bst_node_create() {

    bst_node *node = (bst_node *)calloc(1, sizeof(bst_node));

    if (node == NULL) {
        printf("bst_node_create(): not enough space to create new node\n");
    }

    return node;
}

/*
 * The function takes the root of a bst and inserts node in it.
 * If node already exists, the function does nothing and returns the root
 * without any changes
 */
bst_node *bst_node_insert(bst_node *root, int value) {

    bst_node *temp = NULL;

    if (root == NULL) {
        temp = bst_node_create();
        temp->value = value;
        return temp;
    }

    if (root->value > value) {
        root->left = bst_node_insert(root->left, value);
    }

    if (root->value < value) {
        root->right = bst_node_insert(root->right, value);
    }

    return root;
}

// title
void bst_preorder_print(bst_node *root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->value);
    bst_preorder_print(root->left);
    bst_preorder_print(root->right);
}

// title
void bst_inorder_print(bst_node *root) {
    if (root == NULL) {
        return;
    }

    bst_inorder_print(root->left);
    printf("%d ", root->value);
    bst_inorder_print(root->right);
}

// title
void bst_postorder_print(bst_node *root) {
    if (root == NULL) {
        return;
    }

    bst_postorder_print(root->left);
    bst_postorder_print(root->right);
    printf("%d ", root->value);
}

// deletes the node with the given value, if not in the list, then does nothing
bst_node *bst_node_delete(bst_node *root, int value) {

    if (root == NULL) {
        return NULL;
    }

    bst_node *temp = NULL;

    if (root->value == value) {
        if (root->left == NULL && root->left == NULL) {
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

// deletes the entire bst, return NULL
bst_node *bst_delete(bst_node *root) {

    if (root == NULL) {
        return NULL;
    }
    root->left = bst_delete(root->left);
    root->right = bst_delete(root->right);

    free(root);
    return NULL;
}

/*
 * finds the node with given value, return it
 * if note in the list, return NULL
 */
bst_node *bst_search(bst_node *head, int value) {

    if (head == NULL) {
        return NULL;
    }

    if (value < head->value) {
        return bst_search(head->left, value);
    }
    if (value > head->value) {
        return bst_search(head->right, value);
    }

    return head;
}
