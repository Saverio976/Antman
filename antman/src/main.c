/*
** EPITECH PROJECT, 2022
** ANTMAN
** File description:
** main function
*/

#include <stdlib.h>
#include "project.h"
#include "my_fs.h"
#include "linked_list.h"
#include "binary_tree.h"
#include "my_puts.h"
#include "antman.h"

int starter_main(char const *file, int type)
{
    fs_content_t *buff;
    list_t *list;
    node_t *node;
    int nb_last;

    if (type != 1 && type != 2 && type != 3) {
        return (84);
    }
    buff = fs_get_content(file);
    if (buff == NULL)
        return (84);
    init_tree_list(&node, &list, buff);
    nb_last = print_huffman(buff->content, list);
    write_header(0, nb_last); // TODO
    fs_content_t_free(buff);
    list_t_destroy_all(list);
    node_t_as_node_destroy_all(node);
    return (0);
}
