
/**
 * @file linked_list.h
 * @brief linked list library
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef void (*print_fn)(void *);      //
typedef int (*cmp_fn)(void *, void *); // 0 for equal

typedef struct linked_list_node_struct {
    void *value;
    struct linked_list_node_struct *next;
} linked_list_node;

/**
 * Create a linked list node, with value pointer set to NULL
 *
 * @return the new linked list node
 */
linked_list_node *linked_list_node_create();

/**
 * Create a linked list node, using input value
 *
 * @return the newly created linked list node
 */
linked_list_node *linked_list_node_create_valued(void *value);

/**
 * deletes the entire linked list
 *
 * @param head head of the linked list to delete
 * @return NULL
 */
linked_list_node *linked_list_delete(linked_list_node *head);

/**
 * deletes the node at index count
 *
 * @param head head of the linked list containing node to delete
 * @param count the index of the node to delete
 * @return head of linked list after deletion, if count is too large, does not
 *         do anything
 */
linked_list_node *linked_list_delete_count(linked_list_node *head, int count);

/**
 * Provide the length of input linked list
 *
 * @param head head of the input linked list
 * @return the length of input linked list
 */
int linked_list_length(linked_list_node *head);

/**
 * Find the index of first occurence of the input value in the linked list
 *
 * @param head head of the input linked list
 * @param value target value to search
 * @param compare the compare function to tell whether or not two values are
 *                equal
 * @return the index of first occurence of node containing the value
 */
int linked_list_search(linked_list_node *head, void *value, cmp_fn compare);

/**
 * Insert node at between index count and count + 1
 *
 * @param head head of the input linked list
 * @param node new node to insert
 * @param count index of the new node
 * @return the head of the linked list after insertion
 */
linked_list_node *linked_list_insert_count(linked_list_node *head,
                                           linked_list_node *node, int count);

/**
 * prints one individual linked list node's value
 *
 * @param node the node to print
 * @param print the function used to print the node
 */
void linked_list_node_print(linked_list_node *node, print_fn print);

/**
 * prints the entire linked list
 *
 * @param head head of the linked list to print
 * @param print the function used to print the node
 */
void linked_list_print(linked_list_node *head, print_fn print);

/*__________________delete linked list node___________________*/

#endif
