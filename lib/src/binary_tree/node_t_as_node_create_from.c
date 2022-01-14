/*
** EPITECH PROJECT, 2022
** ANTMAN
** File description:
** create a node from two
*/

#include <stdlib.h>
#include "binary_tree.h"

node_t *node_t_as_node_create_from(node_t *node_left, node_t *node_right)
{
    node_t *node = malloc(sizeof(node_t));

    if (node == NULL) {
        return (node);
    }
    node->is_child = 0;
    node->left = node_left;
    node->right = node_right;
    node->fat = (node_left != NULL) ? node_left->fat : 0;
    node->fat += (node_right != NULL) ? node_right->fat : 0;
    return (node);
}
