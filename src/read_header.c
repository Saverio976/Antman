/*
** EPITECH PROJECT, 2022
** ANTMAN
** File description:
** read header
*/

#include <unistd.h>
#include <stdlib.h>
#include "project.h"
#include "my_fs.h"

static void fill_null_buff(header_t *buff)
{
    buff->dico_size = 0;
    buff->size_minus_byte = 0;
}

header_t read_header(char const *path)
{
    header_t buff;
    int fd = fs_open_ronly(path);
    int size;
    char *buf_text;

    if (fd < 0) {
        fill_null_buff(&buff);
        return (buff);
    }
    size = fs_get_size(path);
    if (size < (int) sizeof(header_t)) {
        fill_null_buff(&buff);
        return (buff);
    }
    buf_text = malloc(size - sizeof(header_t));
    read(fd, buf_text, size - sizeof(header_t));
    read(fd, &buff, sizeof(header_t));
    free(buf_text);
    return (buff);
}
