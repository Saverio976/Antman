/*
** EPITECH PROJECT, 2022
** ANTMAN
** File description:
** the main function
*/

#include <unistd.h>
#include "project.h"
#include "my_puts.h"
#include "my_fs.h"
#include "my_conversions.h"
#include "my_strings.h"

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

static int check_conversion_type(char const *nb_conv)
{
    int is_error = 0;
    int res;

    res = my_atoi_err(nb_conv, &is_error);
    if (is_error == 1) {
        return (0);
    }
    if (res != 1 && res != 2 && res != 3) {
        return (0);
    }
    return (res);
}

static int exec_algo_project(char const *file, char const *nb)
{
    int type;
    int ret_code;

    if (check_file_exists(file) == 0) {
        return (84);
    }
    type = check_conversion_type(nb);
    if (type == 0) {
        return (84);
    }
    ret_code = starter_main(file, type);
    return (ret_code);
}

int main(int ac, char const *av[])
{
    int ret_code = 84;

    if (ac != 3) {
        if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
            ret_code = print_usage(av[0]);
        } else {
            ret_code = 84;
        }
    } else {
        ret_code = exec_algo_project(av[1], av[2]);
    }
    return (ret_code);
}
