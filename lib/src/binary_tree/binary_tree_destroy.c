/*
** EPITECH PROJECT, 2022
** ANTMAN
** File description:
** destroy all
*/

#include <stdlib.h>
#include "binary_tree.h"

void binary_tree_t_destroy(binary_tree_t *tree)
{
    node_t *cursor;
    node_t *tmp;

    if (tree == NULL) {
        return;
    }
    cursor = tree->first;
    while (cursor != NULL) {
        if (cursor->left->left != NULL) {
            free(cursor->left->left);
        }
        if (cursor->left->right != NULL) {
            free(cursor->left->right);
        }
        free(cursor->left);
        tmp = cursor->right;
        free(cursor);
        cursor = tmp;
    }
    free(tree);
}
