/*
** EPITECH PROJECT, 2022
** ANTMAN
** File description:
** read header
*/

#include <unistd.h>
#include "project.h"

header_t read_header(int fd)
{
    header_t buff;

    read(fd, &buff, sizeof(header_t));
    return (buff);
}
