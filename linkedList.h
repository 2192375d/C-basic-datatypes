#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// if marked with //~, that means it should be removed in the future

typedef struct linked_list_node_struct linked_list_node;

linked_list_node *linked_list_node_create();

// linked_list_node *linked_list_node_create_valued(int value); //~

// int linked_list_get_value(linked_list_node *node); //~

// linked_list_node *linked_list_node_next(linked_list_node *node); //~

int linked_list_length(linked_list_node *head);

linked_list_node *linked_list_insert_count(linked_list_node *head,
                                           linked_list_node *node, int count);

void linked_list_node_print(linked_list_node *node);

void linked_list_print(linked_list_node *head);

linked_list_node *linked_list_delete(linked_list_node *head);

linked_list_node *linked_list_delete_count(linked_list_node *head, int count);

linked_list_node *linked_list_search(linked_list_node *head,
                                     linked_list_node *target);

linked_list_node *linked_list_sort(linked_list_node *head);

#endif
