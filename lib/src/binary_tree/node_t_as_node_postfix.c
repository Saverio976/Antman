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

static void print_postfix_buffer(char c, int is_end)
{
    static char buff[255];
    static int index = 0;

    if (index + 1  > 255 || is_end) {
        write(1, buff, index);
        index = 0;
    }
    if (is_end == 0) {
        buff[index++] = c;
    }
}

static int print_to_postfix_rec(node_t *node)
{
    int chars = 0;

    if (node->is_child == 0) {
        if (node->left != NULL) {
            chars += node_t_as_node_postfix(node->left);
        }
        if (node->right != NULL) {
            chars += node_t_as_node_postfix(node->right);
        }
        print_postfix_buffer('\0', 0);
    } else {
        print_postfix_buffer(node->c, 0);
    }
    return (chars + 1);
}

int node_t_as_node_postfix(node_t *node)
{
    int chars = print_to_postfix_rec(node);

    print_postfix_buffer('\0', 1);
    return (chars);
}
