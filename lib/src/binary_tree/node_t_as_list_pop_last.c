/*
** EPITECH PROJECT, 2022
** ANTMAN
** File description:
** pop the last
*/

#include <stddef.h>
#include "binary_tree.h"

node_t *node_t_as_list_pop_last(node_t **list)
{
    node_t *tmp = *list;
    node_t *curs;

    if ((*list) == NULL) {
        return (NULL);
    }
    if ((*list)->next == NULL) {
        tmp = *list;
        *list = NULL;
        return (tmp);
    }
    for (; tmp != NULL && tmp->next != NULL && tmp->next->next != NULL;
            tmp = tmp->next);
    curs = tmp->next;
    tmp->next = NULL;
    return (curs);
}
