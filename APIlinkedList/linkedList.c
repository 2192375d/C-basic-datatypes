#ifndef LINKED_LIST_C
#define LINKED_LIST_C

#include "linkedList.h"
#include "stdio.h"
#include "stdlib.h"

typedef struct linked_list_node_struct {
    int value;
    struct linked_list_node_struct *next;
} linked_list_node;

////////////////////////////////////////////////////////////////

linked_list_node *linked_list_node_create() {
    /*
     * create and return a new node for linked list. if no space available, the
     * function outputs a message and returns null
     */

    linked_list_node *new =
        (linked_list_node *)calloc(1, sizeof(linked_list_node));

    if (new == NULL) {
        printf("linked_list_node_create(): no more space to allocate more "
               "nodes\n");
    }

    return new;
}

////////////////////////////////////////////////////////////////

linked_list_node *linked_list_node_create_valued(int value) {
    /*
     * create and return a new node for linked list, with given value "value"
     * assigned. if no space available, the function outputs a message and
     * returns null
     */

    linked_list_node *new = linked_list_node_create();
    new->value = value;

    return new;
}

////////////////////////////////////////////////////////////////

int linked_list_length(linked_list_node *head) {
    /*
     * Returns the length of the current linked list
     */
    int count = 0;

    while (head != NULL) {
        head = head->next;
        count++;
    }

    return count;
}

////////////////////////////////////////////////////////////////

linked_list_node *linked_list_insert_count(linked_list_node *head,
                                           linked_list_node *node, int count) {
    /*
     * Inserts node at count'th index starting from head.
     * Returns NULL if count is too large. Other invalid count values are not
     * considered
     */

    if (count == 0) {
        node->next = head;
        return node;
    }

    linked_list_node *temp = head;
    int i = 0;

    while (temp != NULL && i < count - 1) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        return node;
    }

    node->next = temp->next;
    temp->next = node;
    return head;
}

////////////////////////////////////////////////////////////////

void linked_list_node_print(linked_list_node *node) {
    /*
     * Print the current node
     */

    printf("%d", node->value);
}

////////////////////////////////////////////////////////////////

void linked_list_print(linked_list_node *head) {
    /*
     * Print the entire linked list
     */

    while (head != NULL) {
        linked_list_node_print(head);
        head = head->next;
    }
}

////////////////////////////////////////////////////////////////

linked_list_node *linked_list_delete(linked_list_node *head) {
    /*
     * deallocate the entire linked list, return NULL
     */

    if (head == NULL) {
        return NULL;
    }

    linked_list_node *temp = NULL;

    while (head != NULL) {
        temp = head->next;
        free(head);
        head = temp;
    }

    return head;
}

////////////////////////////////////////////////////////////////

linked_list_node *linked_list_delete_count(linked_list_node *head, int count) {
    /*
     * Deallocate the input count'th value in the linked list.
     */

    if (head == NULL || count < 0) {
        return head;
    }

    if (count == 0) {
        linked_list_node *next = head->next;
        free(head);
        return next;
    }

    linked_list_node *temp = head;
    int i = 0;
    while (temp != NULL && i < count - 1) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL || temp->next == NULL) {
        return head;
    }

    linked_list_node *to_delete = temp->next;
    temp->next = to_delete->next;
    free(to_delete);

    return head;
}

////////////////////////////////////////////////////////////////

linked_list_node *linked_list_search(linked_list_node *head,
                                     linked_list_node *target) {

    /*
     * returns the target node's address. NULL if not present
     */
    while (head != NULL) {
        if (head->value == target->value) {
            return head;
        }

        head = head->next;
    }

    return NULL;
}

////////////////////////////////////////////////////////////////

linked_list_node *linked_list_sort(linked_list_node *head);

////////////////////////////////////////////////////////////////
/*____________________________________________________________*/

linked_list_node *enqueue(linked_list_node *head, int value) {

    /*
     * insert the input value at the end of the linked list
     */

    // if (head == NULL) {
    //     head = linked_list_node_create();
    //     head->value = value;
    //     return head;
    // }
    //
    // linked_list_node *temp = head;
    // while (temp->next != NULL) {
    //     temp = temp->next;
    // }
    //
    // temp->next = linked_list_node_create();
    // temp->next->value = value;
    //
    // return head;

    head = linked_list_insert_count(head, linked_list_node_create_valued(value),
                                    linked_list_length(head));
    return head;
}

/*____________________________________________________________*/

linked_list_node *dequeue(linked_list_node *head) {

    head = linked_list_delete_count(head, 0);
    return head;

    // if (head == NULL) {
    //     return NULL;
    // }
    //
    // linked_list_node *temp = head->next;
    // free(head);
    // return temp;
}

/*____________________________________________________________*/
#endif
