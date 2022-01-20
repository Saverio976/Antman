/*
** EPITECH PROJECT, 2022
** ANTMAN
** File description:
** the main function
*/

#include "linked_list.h"
#include "my_puts.h"

void print_code(char c, list_t *node)
{
    my_printf("%c\t", c);

    for (int i = node->nb_bit - 1; i >= 0; i--) {
        if ((node->path & 1 << i))
            my_putchar('1');
        else
            my_putchar('0');
    }
    my_putchar('\n');
}
