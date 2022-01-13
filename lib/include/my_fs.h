/*
** EPITECH PROJECT, 2021
** LIBMY
** File description:
** the file part of libmy
*/

#ifndef MY_FS_H_
    #define MY_FS_H_

typedef struct fs_content_t fs_content_t;

struct fs_content_t {
    char *content;
    int size;
};

// get content of file
fs_content_t *fs_get_content(char const *);

// free the result of fs_get_content
void fs_content_t_free(fs_content_t *);

// get size of file
int fs_get_size(char const *);

// open read only file
int fs_open_ronly(char const *);

#endif
