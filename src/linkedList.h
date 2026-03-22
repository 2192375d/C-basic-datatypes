// linkedList.h

/*
 * This file takes part of Lumiere's datatype libraries in C
 * The current file contains the API documentation of all functions from the
 * linked list library
 *
 * Note that the linked lists here take only works with integer
 *
 * No further documentation is provided in this file because the purpose of each
 * functions are self explainatory from their name
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct linked_list_node_struct {
    int value;
    struct linked_list_node_struct *next;
} linked_list_node;

/*__________________create linked list node___________________*/
linked_list_node *linked_list_node_create();

linked_list_node *linked_list_node_create_valued(int value);

/*__________________other linked list functionalities_________*/

void linked_list_node_print(linked_list_node *node);

int linked_list_length(linked_list_node *head);

linked_list_node *linked_list_search(linked_list_node *head,
                                     linked_list_node *target);

/*__________________insert linked list node___________________*/
linked_list_node *linked_list_insert_count(linked_list_node *head,
                                           linked_list_node *node, int count);

linked_list_node *linked_list_insert_end(linked_list_node *head, int value);

void linked_list_print(linked_list_node *head);

/*__________________delete linked list node___________________*/
linked_list_node *linked_list_delete(linked_list_node *head);

linked_list_node *linked_list_delete_count(linked_list_node *head, int count);

linked_list_node *linked_list_delete_end(linked_list_node *head);

/*__________________linked list and other datatype___________*/
linked_list_node *array_to_linked_list(int array[], int N);

#endif
