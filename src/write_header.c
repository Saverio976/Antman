/*
** EPITECH PROJECT, 2022
** ANTMAN
** File description:
** write header
*/

#include <unistd.h>

void write_header(unsigned int dico_char_size)
{
    write(1, &dico_char_size, sizeof(unsigned int));
}
