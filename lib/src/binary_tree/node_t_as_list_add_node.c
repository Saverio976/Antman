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
    if (node == NULL) {
        return (NULL);
    }
    if (list == NULL) {
        node->next = NULL;
        return (node);
    }
    node->next = list->next;
    list->next = node;
    return (list);
}
