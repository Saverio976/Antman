/*
** EPITECH PROJECT, 2022
** ANTMAN
** File description:
** gets the code of each char
*/

#include <stdlib.h>
#include <unistd.h>
#include "linked_list.h"
#include "my_puts.h"

static int set_bit(char value, int is_end)
{
    static int nb_bits = 0;
    static char buf[255];
    static int index = 0;

    if (!is_end && nb_bits < 8) {
        buf[index] = buf[index] << 1;
        buf[index] += value;
        nb_bits++;
    } else {
        index++;
        nb_bits = 0;
    }
    if (is_end || index > 255) {
        write(1, buf, index - 1);
        index = 0;
        nb_bits = 0;
        return (nb_bits);
    }
    return (nb_bits);
}

static int get_code(list_t *list, unsigned char c) {
    list_t *node = list_t_get_index(list, c);
    int nb_bit = 0;

    if (node == NULL) {
        return (0);
    }
    for (int i = node->nb_bit; i > 0; i--)
        nb_bit = set_bit(node->path & 1 << i, 0);
    return (nb_bit);
}

int print_huffman(char *str, list_t *list)
{
    int nb_bit = 0;

    for (int i = 0; str[i]; i++)
        nb_bit = get_code(list, str[i]);
    set_bit(0, 1);
    return (8 - nb_bit);
}
