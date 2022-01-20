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

int starter_main(char const *file, __attribute__((unused)) int type)
{
    fs_content_t *buff;
    list_t *list;
    node_t *node;
    short int nb_last;
    int nb_dico;

    buff = fs_get_content(file);
    if (buff == NULL)
        return (84);
    init_tree_list(&node, &list, buff);
    nb_dico = node_t_as_node_postfix(node, '\0');
    nb_last = print_huffman(buff->content, list);
    write_header(nb_dico, nb_last);
    fs_content_t_free(buff);
    list_t_destroy_all(list);
    node_t_as_node_destroy_all(node);
    return (0);
}
