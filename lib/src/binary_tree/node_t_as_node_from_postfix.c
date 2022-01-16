/*
** EPITECH PROJECT, 2022
** ANTMAN
** File description:
** from postfix buffer
*/

#include <stddef.h>
#include "binary_tree.h"

node_t *node_t_as_node_from_postfix(char *str, int size, char delim)
{
    node_t *node = NULL;
    node_t *node_left;
    node_t *node_right;

    for (int i = 0; i < size; i++) {
        if (str[i] != delim) {
            node = node_t_as_list_add_char(node, str[i]);
        } else {
            node_right = node_t_as_list_pop_last(&node);
            node_left = node_t_as_list_pop_last(&node);
            node = node_t_as_node_create_from(node_left, node_right);
        }
    }
    return (node);
}
