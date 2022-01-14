/*
** EPITECH PROJECT, 2022
** ANTMAN
** File description:
** print postfix and return how many print
*/

#include <stddef.h>
#include "binary_tree.h"
#include "my_puts.h"

int node_t_as_node_postfix(node_t *node)
{
    int chars = 0;

    if (node->is_child == 0) {
        if (node->left != NULL) {
            chars += node_t_as_node_postfix(node->left);
        }
        if (node->right != NULL) {
            chars += node_t_as_node_postfix(node->right);
        }
        my_putchar('\0');
    } else {
        my_putchar(node->c);
    }
    return (chars + 1);
}
