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

static int set_bit(int value, int is_end)
{
    static int nb_bits = 0;
    static unsigned char buf[255] = {0};
    static int index = 0;

    if (!is_end && nb_bits < 7) {
        buf[index] = buf[index] << 1;
        buf[index] += value;
        nb_bits++;
    } else {
        buf[index] = buf[index] << 1;
        buf[index] += value;
        index++;
        buf[index] = 0;
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
    int value = 0;

    if (node == NULL) {
        return (0);
    }
    for (int i = node->nb_bit - 1; i >= 0; i--) {
        value = ((1 << i & node->path) > 0) ? 1 : 0;
        nb_bit = set_bit(value, 0);
    }
    return (nb_bit);
}

int print_huffman(char *str, list_t *list)
{
    int nb_bit = 0;

    for (int i = 0; str[i]; i++)
        nb_bit = get_code(list, str[i]);
    for (int i = 0; i < 8 - nb_bit; i++) {
        set_bit(0, 0);
    }
    set_bit(0, 1);
    return (8 - nb_bit);
}
