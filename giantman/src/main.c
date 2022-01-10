/*
** EPITECH PROJECT, 2022
** GIANTMAN
** File description:
** main function
*/

#include <stdlib.h>
#include "my_fs.h"
#include "my_puts.h"

int main(int ac, char **av)
{
    fs_content_t *buff;

    if (ac < 2)
        return (84);
    buff = fs_get_content(av[1]);
    if (buff == NULL)
        return (84);
    my_putstr(buff->content);
    free(buff->content);
    free(buff);
    return (0);
}
