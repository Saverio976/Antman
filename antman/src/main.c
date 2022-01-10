/*
** EPITECH PROJECT, 2022
** ANTMAN
** File description:
** main function
*/

#include <stdlib.h>
#include "my_fs.h"
#include "my_puts.h"
#include "linked_list.h"
#include "antman.h"

int main(int ac, char **av)
{
    fs_content_t *buff;
    list_t *list;

    if (ac < 2)
        return (84);
    buff = fs_get_content(av[1]);
    if (buff == NULL)
        return (84);
    my_putstr(buff->content);
    list = launch_parsing(buff->content);
    list_t_destroy_all(list);
    free(buff->content);
    free(buff);
    return (0);
}
