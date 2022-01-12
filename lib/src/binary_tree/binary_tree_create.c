/*
** EPITECH PROJECT, 2022
** ANTMAN
** File description:
** create a binary tree
*/

#include <stdlib.h>
#include "binary_tree.h"

static void set_value_null_node(node_t *node)
{
    node->is_child = 0;
    node->left = NULL;
    node->right = NULL;
}

binary_tree_t *binary_tree_t_create(void)
{
    binary_tree_t *new = malloc(sizeof(binary_tree_t));

    if (new == NULL) {
        return (NULL);
    }
    new->first = malloc(sizeof(node_t));
    if (new->first == NULL) {
        free(new);
        return (NULL);
    }
    new->priv_cursor = new->first;
    set_value_null_node(new->first);
    new->first->left = malloc(sizeof(node_t));
    if (new->first->left == NULL) {
        free(new);
        return (NULL);
    }
    set_value_null_node(new->first->left);
    return (new);
}
