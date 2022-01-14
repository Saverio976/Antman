/*
** EPITECH PROJECT, 2022
** ANTMAN
** File description:
** write header
*/

#include <unistd.h>
#include "project.h"

void write_header(unsigned int dico_char_size, short int size_minus_byte)
{
    header_t head = {dico_char_size, size_minus_byte};

    write(1, &head, sizeof(header_t));
}
