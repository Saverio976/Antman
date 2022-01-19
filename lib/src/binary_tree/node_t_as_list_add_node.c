/*
** EPITECH PROJECT, 2022
** ANTMAN
** File description:
** add a node
*/

#include <stdlib.h>
#include "binary_tree.h"

node_t *node_t_as_list_add_node(node_t *list, node_t *node)
{
    node_t *cursor;

    if (node == NULL) {
        return (NULL);
    }
    if (list == NULL) {
        node->next = NULL;
        return (node);
    }
    for (cursor = list; cursor != NULL && cursor->next != NULL;
            cursor = cursor->next);
    node->next = cursor->next;
    cursor->next = node;
    return (list);
}
