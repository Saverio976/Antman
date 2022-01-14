/*
** EPITECH PROJECT, 2022
** ANTMAN
** File description:
** check if contains
*/

#include <stddef.h>
#include "binary_tree.h"

node_t *node_t_as_list_contains(node_t *list, unsigned char c)
{
    node_t *tmp = list;
    int condition = 1;

    while (tmp != NULL && condition) {
        if (tmp->is_child && tmp->c == c) {
            condition = 0;
        } else {
            tmp = tmp->next;
        }
    }
    if (tmp == NULL) {
        return (NULL);
    } else {
        return tmp;
    }
}
