/*
** EPITECH PROJECT, 2022
** ANTMAN
** File description:
** add
*/

#include <stdlib.h>
#include "binary_tree.h"

node_t *node_t_as_list_add_char(node_t *list, unsigned char c)
{
    node_t *new = malloc(sizeof(node_t));

    if (new == NULL) {
        return (NULL);
    }
    new->c = c;
    new->fat = 1;
    new->is_child = 1;
    if (list == NULL) {
        new->next = NULL;
        return (new);
    }
    new->next = list->next;
    list->next = new;
    return (list);
}
