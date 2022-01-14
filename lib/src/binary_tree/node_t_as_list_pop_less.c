/*
** EPITECH PROJECT, 2022
** ANTMAN
** File description:
** pop the less frequency
*/

#include <stddef.h>
#include "binary_tree.h"

static void update_ptr_node(node_t *list, node_t *min)
{
    node_t *tmp = list;

    while (tmp->next != NULL && tmp->next != min) {
        tmp = tmp->next;
    }
    tmp->next = min->next;
}

node_t *node_t_as_list_pop_less(node_t **list)
{
    node_t *min = *list;

    if (*list == NULL) {
        return (NULL);
    }
    for (node_t *cursor = *list; cursor != NULL; cursor = cursor->next) {
        if (cursor->fat < min->fat) {
            min = cursor;
        }
    }
    if (min == *list) {
        *list = (*list)->next;
    } else {
        update_ptr_node(*list, min);
    }
    return (min);
}
