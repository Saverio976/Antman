/*
** EPITECH PROJECT, 2022
** ANTMAN
** File description:
** gets the code of each char
*/

#include <stdlib.h>
#include <unistd.h>
#include "linked_list.h"

int set_bit(unsigned char *content, char value, int index)
{
    static int nb_bits = 0;

    if (nb_bits < 8) {
        content[index] = content[index] << 1;
        content[index] += value;
        nb_bits++;
    } else {
        index++;
        nb_bits = 0;
        if (index > 1024) {
            write(1, content, 1024);
            index = 0;
        }
    }
    return (nb_bits);
}

int get_code(list_t *list, unsigned char c, unsigned char *content, int index) {
    list_t *node = list_t_get_index(list, c);
    int nb_bit = 0;

    if (node == NULL) {
        return (0);
    }
    for (int i = 0; i < node->nb_bit; i++)
        nb_bit = set_bit(content, node->path & 1 << i, index);
    return (nb_bit);
}

int print_huffman(char *str, list_t *list)
{
    static unsigned char buffer[1024] = {0};
    static int index = 0;
    int nb_bit = 0;

    for (int i = 0; str[i]; i++)
        nb_bit = get_code(list, str[i], buffer, index);
    write(1, buffer, index);
    return (8 - nb_bit);
}
