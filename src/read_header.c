/*
** EPITECH PROJECT, 2022
** ANTMAN
** File description:
** read header
*/

#include <unistd.h>

unsigned int read_header(int fd)
{
    unsigned int buff;

    read(fd, &buff, sizeof(unsigned int));
    return (buff);
}
