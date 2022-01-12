/*
** EPITECH PROJECT, 2022
** ANTMAN
** File description:
** create a binary tree from each char of an char *
*/

#include <stddef.h>
#include "binary_tree.h"

binary_tree_t *binary_tree_t_from_infix(const char *array, int arr_size)
{
    binary_tree_t *tree = binary_tree_t_create();

    for (int i = 0; tree != NULL && i < arr_size; i++) {
        tree = binary_tree_t_push_huffman(tree, array[i]);
    }
    return (tree);
}
