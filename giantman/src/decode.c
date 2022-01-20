/*
** EPITECH PROJECT, 2022
** GIANTMAN
** File description:
** decodes the text
*/

#include <unistd.h>
#include "binary_tree.h"
#include "project.h"

static void print_bufferer(char c, int is_end)
{
    static char buf[255];
    static int index = 0;

    if (is_end || index + 1 > 255) {
        write(1, buf, index);
        index = 0;
    }
    if (!is_end) {
        buf[index++] = c;
    }
}

static node_t *get_bits(char c, node_t *tmp, node_t *tree, int last_nbyte)
{
    for (int i = 8 - 1; i >= last_nbyte; i--) {
        if (c & 1 << i) {
            tmp = tmp->right;
        } else {
            tmp = tmp->left;
        }
        if (tmp->is_child) {
            print_bufferer(tmp->c, 0);
            tmp = tree;
        }
    }
    return (tmp);
}

void decode_str(unsigned char *str, node_t *tree, int last_nbyte,
    long int size)
{
    node_t *tmp = tree;
    int i = 0;

    if (str == NULL || tree == NULL) {
        return;
    }
    for (; i < size - 1; i++) {
        tmp = get_bits(str[i], tmp, tree, 0);
    }
    get_bits(str[i], tmp, tree, last_nbyte);

    print_bufferer('\0', 1);
}
