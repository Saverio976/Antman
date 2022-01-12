/*
** EPITECH PROJECT, 2022
** ANTMAN
** File description:
** print binary tree to infix
*/

#include <stdlib.h>
#include "binary_tree.h"
#include "my_puts.h"

void binary_tree_t_to_infix(binary_tree_t *tree)
{
    node_t *cursor;

    if (tree == NULL) {
        return;
    }
    cursor = tree->first;
    while (cursor != NULL) {
        if (cursor->left->left != NULL) {
            my_putchar(cursor->left->left->c);
        }
        if (cursor->left->right != NULL) {
            my_putchar(cursor->left->right->c);
        }
        cursor = cursor->right;
    }
}
