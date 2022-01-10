/*
** EPITECH PROJECT, 2021
** LIBMY
** File description:
** get filess content from a buffer
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_fs.h"
#include "my_strings.h"

static fs_content_t *error_size(int size, int fd)
{
    fs_content_t *content;

    close(fd);
    if (size < 0) {
        return (NULL);
    }
    content = malloc(sizeof(fs_content_t));
    if (content == NULL) {
        return (NULL);
    }
    content->content = malloc(sizeof(char));
    if (content->content == NULL) {
        free(content);
        return (NULL);
    }
    content->size = 0;
    content->content[0] = '\0';
    return (content);
}

static fs_content_t *malloc_struct(int fd, int size)
{
    fs_content_t *content = malloc(sizeof(fs_content_t));

    if (content == NULL) {
        close(fd);
        return (NULL);
    }
    content->content = malloc(sizeof(char) * (size + 1));
    if (content->content == NULL) {
        free(content);
        close(fd);
        return (NULL);
    }
    return (content);
}

static fs_content_t *fill_buffer(int fd, fs_content_t *content, int size)
{
    int nbyte = read(fd, content->content, size);

    if (nbyte != size) {
        free(content->content);
        free(content);
        close(fd);
        return (NULL);
    }
    content->content[size] = '\0';
    return (content);
}

fs_content_t *fs_get_content(char const *path)
{
    fs_content_t *content;
    char *buffer = NULL;
    int size = 0;
    int fd = fs_open_ronly(path);

    if (fd < 0) {
        return (NULL);
    }
    size = fs_get_size(path);
    if (size <= 0) {
        return (error_size(size, fd));
    }
    content = malloc_struct(fd, size);
    if (buffer == NULL) {
        return (NULL);
    }
    content = fill_buffer(fd, content, size);
    return (content);
}
