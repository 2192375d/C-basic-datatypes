#include <stdio.h>
#include <stdlib.h>

#include "avl.h"
#include "bst.h"
#include "utils.h"

void update_height(avl_node *root) {
    if (!root) {
        printf("update_height: root does not exist");
        return;
    }

    root->height = 1 + ds_max(avl_height(root->left), avl_height(root->right));
}

avl_node *rebalance(avl_node *root) {
    avl_node *temp = NULL;

    if (avl_height(root->right) - avl_height(root->left) > 1) {
        temp = root->right;

        if (avl_height(temp->right) >= avl_height(temp->left)) {
            root = avl_rotation_left(root);
        } else {
            root->right = avl_rotation_right(root->right);
            root = avl_rotation_left(root);
        }
    } else if (avl_height(root->right) - avl_height(root->left) < -1) {
        temp = root->left;

        if (avl_height(temp->right) <= avl_height(temp->left)) {
            root = avl_rotation_right(root);
        } else {
            root->left = avl_rotation_left(root->left);
            root = avl_rotation_right(root);
        }
    }

    return root;
}

avl_node *avl_node_create() {

    avl_node *node = (avl_node *)calloc(1, sizeof(avl_node));

    if (node == NULL) {
        printf("avl_node_create(): not enough space to create new node\n");
        return NULL;
    }

    node->left = NULL;
    node->right = NULL;
    node->value = 0;
    node->height = 1;

    return node;
}

avl_node *avl_node_create_valued(int value) {

    avl_node *node = avl_node_create();
    node->value = value;

    return node;
}

int avl_height(avl_node *root) {
    if (!root) {
        return 0;
    }

    return root->height;
}

avl_node *avl_rotation_left(avl_node *root) {

    // assumes root->right exist
    avl_node *node_right = root->right;
    avl_node *node_temp = node_right->left;

    node_right->left = root;
    root->right = node_temp;

    update_height(root);
    update_height(node_right);

    return node_right;
}

avl_node *avl_rotation_right(avl_node *root) {

    // assumes root->left exist
    avl_node *node_left = root->left;
    avl_node *node_temp = node_left->right;

    node_left->right = root;
    root->left = node_temp;

    update_height(root);
    update_height(node_left);

    return node_left;
}

void avl_preorder_print(avl_node *root) {
    bst_node *node = (bst_node *)root;

    bst_preorder_print(node);
}

void avl_inorder_print(avl_node *root) {
    bst_node *node = (bst_node *)root;

    bst_inorder_print(node);
}

void avl_postorder_print(avl_node *root) {
    bst_node *node = (bst_node *)root;

    bst_postorder_print(node);
}

avl_node *avl_node_insert(avl_node *root, int value) {

    avl_node *temp = NULL;

    if (root == NULL) {
        temp = avl_node_create_valued(value);
        return temp;
    }

    if (root->value == value) {
        printf("avl_node_insert: No duplicated node allowed to insert\n");
        return NULL;
    }

    if (value < root->value) {
        root->left = avl_node_insert(root->left, value);
    }

    else if (value > root->value) {
        root->right = avl_node_insert(root->right, value);
    }

    update_height(root);

    root = rebalance(root);

    return root;
}

avl_node *avl_node_delete(avl_node *root, int value) {

    if (root == NULL) {
        printf("avl_node_delete: target node not found");
        return NULL;
    }

    avl_node *temp = NULL;

    if (root->value == value) {
        // do the delete

        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        if (root->left == NULL) {
            temp = root->right;
            free(root);
            return temp;
        }

        if (root->right == NULL) {
            temp = root->left;
            free(root);
            return temp;
        }

        temp = root->right;

        while (temp->left != NULL) {
            temp = temp->left;
        }

        root->value = temp->value;
        root->right = avl_node_delete(root->right, temp->value);

        update_height(root);
        root = rebalance(root);

        return root;
    }

    if (value < root->value) {
        root->left = avl_node_delete(root->left, value);
    } else {
        root->right = avl_node_delete(root->right, value);
    }

    update_height(root);
    root = rebalance(root);

    return root;
}

avl_node *avl_delete(avl_node *root) {
    if (root == NULL) {
        return NULL;
    }
    root->left = avl_delete(root->left);
    root->right = avl_delete(root->right);
    free(root);
    return NULL;
}

avl_node *avl_search(avl_node *root, int value) {
    if (root == NULL) {
        printf("avl_search: the node does not exist");
        return NULL;
    }

    if (value < root->value) {
        return avl_search(root->left, value);
    }

    if (value > root->value) {
        return avl_search(root->right, value);
    }

    return root;
}
