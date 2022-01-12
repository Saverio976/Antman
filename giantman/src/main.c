/*
** EPITECH PROJECT, 2022
** GIANTMAN
** File description:
** main function
*/

#include <stdlib.h>
#include "my_fs.h"
#include "my_puts.h"
#include "project.h"

int starter_main(char const *file, int type)
{
    fs_content_t *buff;

    if (type != 1 && type != 2 && type != 3) {
        return (84);
    }
    buff = fs_get_content(file);
    if (buff == NULL)
        return (84);
    my_putstr(buff->content);
    free(buff->content);
    free(buff);
    return (0);
}
