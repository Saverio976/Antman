/*
** EPITECH PROJECT, 2022
** LIBMY
** File description:
** len of node_t as list
*/

#include <stddef.h>
#include "binary_tree.h"

int node_t_as_list_len(node_t *list)
{
    int len = 0;

    if (list == NULL) {
        return (0);
    }
    for (; list != NULL; list = list->next) {
        len += 1;
    }
    return (len);
}
