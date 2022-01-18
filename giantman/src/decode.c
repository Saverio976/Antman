/*
** EPITECH PROJECT, 2022
** GIANTMAN
** File description:
** decodes the text
*/

#include "binary_tree.h"
#include <unistd.h>

void decode_str(char *str, node_t *tree)
{
    node_t *tmp = tree;
    static char buffer[1024];
    static int index = 0;

    for (int i = 0; str[i]; i++) {
        tmp = get_bits(str[i], tmp, buffer, index);
        if (tmp->c) {
            tmp = tree;
        }
    }
    write(1, buffer, index);
}

static int check_char(char *buffer, int index, node_t *tmp)
{
    if (tmp->c) {
        buffer[index] = tmp->c;
        index++;
        if (index > 1024) {
            index = 0;
            write(1, buffer, 1024);
        }
    }
    return (index);
}

static node_t *get_bits(char c, node_t *tree, char *buffer, int index)
{
    node_t *tmp = tree;

    for (int i = 8; i > 0; i--) {
        if (c & 1 << i) {
            tmp = tmp->right;
        } else {
            tmp = tmp->left;
        }
        index = check_char(buffer, index, tmp);
    }
    return (tmp);
}
