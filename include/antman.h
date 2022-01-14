/*
** EPITECH PROJECT, 2022
** ANTMAN
** File description:
** antman
*/

#ifndef ANTMAN_H_
    #define ANTMAN_H_

    #include "linked_list.h"
    #include "binary_tree.h"
    #include "my_fs.h"

int print_huffman(char *str, list_t *list);

void init_tree_list(node_t **node, list_t **list, fs_content_t *cont);

#endif
