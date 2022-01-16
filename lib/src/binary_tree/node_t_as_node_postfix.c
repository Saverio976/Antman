/*
** EPITECH PROJECT, 2022
** ANTMAN
** File description:
** print postfix and return how many print
*/

#include <stddef.h>
#include <unistd.h>
#include "binary_tree.h"
#include "my_puts.h"

static int print_postfix_buffer(char c, int is_end)
{
    static char buff[255];
    static int index = 0;
    int tmp = 0;

    if (index + 1 > 255 || is_end) {
        write(1, buff, index);
        tmp = index;
        index = 0;
    }
    if (is_end == 0) {
        buff[index++] = c;
    }
    return (tmp);
}

static int print_to_postfix_rec(node_t *node, char delim)
{
    int chars = 0;

    if (node->is_child == 0) {
        if (node->left != NULL) {
            chars += print_to_postfix_rec(node->left, delim);
        }
        if (node->right != NULL) {
            chars += print_to_postfix_rec(node->right, delim);
        }
        chars += print_postfix_buffer(delim, 0);
    } else {
        chars += print_postfix_buffer(node->c, 0);
    }
    return (chars);
}

int node_t_as_node_postfix(node_t *node, char delim)
{
    int chars = print_to_postfix_rec(node, delim);

    chars += print_postfix_buffer(delim, 1);
    return (chars);
}
