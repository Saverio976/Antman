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

static int read_fd(int fd, int size, header_t *buff)
{
    char *buf_text;
    int size_mal = size - sizeof(header_t);

    buf_text = malloc(size_mal + 1);
    if (buf_text == NULL) {
        return (0);
    }
    if (read(fd, buf_text, size_mal) < 0) {
        free(buf_text);
        fill_null_buff(buff);
        return (0);
    }
    free(buf_text);
    if (read(fd, buff, sizeof(header_t)) < 0) {
        fill_null_buff(buff);
        return (0);
    }
    return (1);
}

header_t read_header(char const *path)
{
    header_t buff;
    int fd = fs_open_ronly(path);
    int size;

    if (fd < 0) {
        fill_null_buff(&buff);
        return (buff);
    }
    size = fs_get_size(path);
    if (size < (int) sizeof(header_t)) {
        fill_null_buff(&buff);
        return (buff);
    }
    read_fd(fd, size, &buff);
    return (buff);
}
