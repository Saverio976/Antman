/*
** EPITECH PROJECT, 2022
** ANTMAN
** File description:
** push a value using the priv_cursor
*/

#include "binary_tree.h"
#include <stdlib.h>

static node_t *create_new_right(node_t *node)
{
    node->right = malloc(sizeof(node_t));
    if (node->right == NULL) {
        return (NULL);
    }
    node->right->is_child = 0;
    node->right->right = NULL;
    node->right->left = malloc(sizeof(node_t));
    if (node->right->left == NULL) {
        free(node->right);
        return (NULL);
    }
    node->right->left->is_child = 0;
    node->right->left->right = NULL;
    node->right->left->left = NULL;
    return (node->right);
}

binary_tree_t *binary_tree_t_push_huffman(binary_tree_t *tree, char c)
{
    node_t *new = malloc(sizeof(node_t));

    if (new == NULL) {
        return (NULL);
    }
    new->c = c;
    new->is_child = 1;
    new->left = NULL;
    new->right = NULL;
    if (tree->priv_cursor->left->left == NULL) {
        tree->priv_cursor->left->left = new;
    } else if (tree->priv_cursor->left->right == NULL) {
        tree->priv_cursor->left->right = new;
    } else {
        tree->priv_cursor = create_new_right(tree->priv_cursor);
        tree->priv_cursor->left->left = new;
    }
    return (tree);
}
