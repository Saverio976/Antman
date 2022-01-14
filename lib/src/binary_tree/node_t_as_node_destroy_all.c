/*
** EPITECH PROJECT, 2022
** ANTMAN
** File description:
** destroy all as a binary tree
*/

#include <stdlib.h>
#include "binary_tree.h"

void node_t_as_node_destroy_all(node_t *node)
{
    if (node->is_child == 0 && node->left != NULL) {
        node_t_as_node_destroy_all(node->left);
    }
    if (node->is_child == 0 && node->right != NULL) {
        node_t_as_node_destroy_all(node->right);
    }
    free(node);
}
