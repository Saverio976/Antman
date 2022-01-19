/*
** EPITECH PROJECT, 2022
** GIANTMAN
** File description:
** decodes the text
*/

#include <unistd.h>
#include "binary_tree.h"

static void print_bufferer(char c, int is_end)
{
    static char buf[255];
    static int index = 0;

    if (is_end || index + 1 > 255) {
        write(1, buf, index - 1);
        index = 0;
    }
    if (!is_end) {
        printf("%c\n", c);
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

static void print_code(char c)
{
    for (int i = 8 - 1; i >= 0; i--) {
        if (c & 1 << i)
            my_putchar('1');
        else
            my_putchar('0');
    }
    my_putchar('\n');
}

void decode_str(unsigned char *str, node_t *tree, int last_nbyte)
{
    node_t *tmp = tree;
    int i = 0;

    if (str == NULL || tree == NULL) {
        return;
    }
    for (; str[i] != '\0'; i++) {
        print_code(str[i]);
        tmp = get_bits(str[i], tmp, tree, 0);
    }
    print_code(str[i]);
    get_bits(str[i], tmp, tree, 8 - last_nbyte);
    print_bufferer('\0', 1);
}
//METTRE SIZE EN PARAMETRE POUR LA CONDITION DE FIN POUR PAS DEPASSER
