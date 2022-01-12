/*
** EPITECH PROJECT, 2022
** ANTMAN
** File description:
** the main function
*/

#include "project.h"
#include "my_puts.h"
#include "my_fs.h"
#include <unistd.h>

static int print_usage(char const *exe)
{
    my_printf("USAGE:\n\t%s (file type)|(-h)\n", exe);
    my_putstr("DESCRIPTION:\n\tfile type\n");
    my_putstr("\t\t\tfile\tfile to process\n");
    my_putstr("\t\t\ttype\t1: text file; 2: html file; 3: ppm file\n");
    my_putstr("\t-h\tshow this usage message\n");
    return (0);
}

static int check_file_exists(char const *file)
{
    int fd = fs_open_ronly(file);

    if (fd <= 0) {
        return (0);
    }
    close(fd);
    return (1);
}

int main(int ac, char const *av[])
{
    if (ac != 3) {
        if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
            return (print_usage(av[0]));
        }
        return (84);
    }
    if ((av[2][0] == '1' || av[2][0] == '2' || av[2][0] == '3') &&
            av[2][1] == '\0') {
        if (check_file_exists(av[1]) == 0) {
            return (84);
        }
        return (starter_main(av[1], av[2][0] - '0'));
    } else {
        return (84);
    }
}
