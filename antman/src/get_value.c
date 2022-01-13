/*
** EPITECH PROJECT, 2022
** ANTMAN
** File description:
** gets the code of each char
*/

#include "linked_list.h"
#include <stdlib.h>
#include <unistd.h>

int set_bit(unsigned char *content, char value, int index)
{
    static int nb_bits = 0;

    if (nb_bits < 8) {
        content[index] << 1;
        content[index] += value;
        nb_bits++;
    } else {
        index++;
        if (index > 1028) {
            write(1, content, 1028);
            index = 0;
        }
        nb_bits = 0;
    }
    return (nb_bits);
}

int get_code(list_t *list, char c, unsigned char *content, int index) {
    list_t *node = list_t_contains(list, c);
    int node_index = node->index;
    int nb_bit = 0;

    for (int i = 0; i < (node_index / 2); i++)
        nb_bit = set_bit(content, 1, index);
    nb_bit = set_bit(content, 0, index);
    if (index % 2)
        nb_bit = set_bit(content, 0, index);
    else
        nb_bit = set_bit(content, 1, index);
    return (nb_bit);
}

int print_huffman(char *str, list_t *list)
{
    static unsigned char buffer[1028] = {0};
    static int index = 0;
    int nb_bit = 0;

    for (int i = 0; str[i]; i++) {
        nb_bit = get_code(list, str[i], buffer, index);
    }
    write(1, buffer, index);
    return (8 - nb_bit);
}
