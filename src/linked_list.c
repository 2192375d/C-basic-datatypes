#include "./linked_list.h"
#include "stdio.h"
#include "stdlib.h"

////////////////////////////////////////////////////////////////

linked_list_node *linked_list_node_create() {
    /*
     * create and return a new node for linked list. if no space available, the
     * function outputs a message and returns null
     */

    linked_list_node *new =
        (linked_list_node *)calloc(1, sizeof(linked_list_node));

    if (new == NULL) {
        fprintf(stderr,
                "linked_list_node_create(): no more space to allocate more "
                "nodes\n");
        return NULL;
    }

    new->value = NULL;

    return new;
}

////////////////////////////////////////////////////////////////

linked_list_node *linked_list_node_create_valued(void *value) {
    /*
     * create and return a new node for linked list, with given value "value"
     * assigned. if no space available, the function outputs a message and
     * returns null
     */

    linked_list_node *new_node = linked_list_node_create();
    new_node->value = value;

    return new_node;
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

void linked_list_node_print(linked_list_node *node, print_fn print) {
    /*
     * Print the current node
     */

    print(node->value);
}

////////////////////////////////////////////////////////////////

void linked_list_print(linked_list_node *head, print_fn print) {
    /*
     * Print the entire linked list
     */

    while (head != NULL) {
        linked_list_node_print(head, print);
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
///
// linked_list_node *linked_list_delete_end(linked_list_node *head) {
//
//     if (head == NULL) {
//         return head;
//     }
//
//     linked_list_node *p = head;
//
//     if (p->next == NULL) {
//         free(p->next);
//         p->next = NULL;
//         return head;
//     }
//
//     while (p->next->next != NULL) {
//         p = p->next;
//     }
//
//     free(p->next);
//     p->next = NULL;
//     return head;
// }

////////////////////////////////////////////////////////////////

int linked_list_search(linked_list_node *head, void *value, cmp_fn cmp) {

    int count = 0;
    while (head != NULL) {
        if (cmp(head->value, value) == 0) {
            return count;
        }
        count++;
        head = head->next;
    }

    return -1;
}

////////////////////////////////////////////////////////////////

// linked_list_node *linked_list_insert_end(linked_list_node *head, void *value)
// {
//
//     while (head != NULL) {
//         head = head->next;
//     }
//
//     head = linked_list_node_create_valued(value);
//     return head;
// }

////////////////////////////////////////////////////////////////
