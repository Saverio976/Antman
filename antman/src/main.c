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

static binary_tree_t *convert_list_to_binary(list_t *list)
{
    binary_tree_t *tree = binary_tree_t_create();
    list_t *tmp;

    while (list != NULL) {
        tmp = list_t_pop_less_frequency(&list);
        binary_tree_t_push_huffman(tree, tmp->word);
    }
    return (tree);
}

int starter_main(char const *file, int type)
{
    fs_content_t *buff;
    list_t *list;
    binary_tree_t *tree;

    my_putnbr(type);
    if (type != 1 && type != 2 && type != 3) {
        return (84);
    }
    buff = fs_get_content(file);
    if (buff == NULL)
        return (84);
    list = get_list_from_buff(buff->content, buff->size);
    tree = convert_list_to_binary(list);
    fs_content_t_free(buff);
    return (0);
}
