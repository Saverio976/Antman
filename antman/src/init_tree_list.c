/*
** EPITECH PROJECT, 2022
** ANTMAN
** File description:
** int tree and the correpodant list
*/

#include <stddef.h>
#include "my_fs.h"
#include "binary_tree.h"
#include "linked_list.h"

static void fill_node_list(node_t **node, list_t **list, fs_content_t *cont)
{
    node_t *tmp;

    *node = NULL;
    *list = NULL;
    for (int i = 0; i < 255; i++) {
        *list = list_t_add(*list, 0);
    }
    for (int i = 0; i < cont->size; i++) {
        tmp = node_t_as_list_contains(*node, cont->content[i]);
        if (tmp == NULL) {
            *node = node_t_as_list_add_char(*node, cont->content[i]);
        } else {
            tmp->fat = tmp->fat + 1;
        }
    }
}

static void update_recussiv_path(node_t *node, int pad, list_t *list)
{
    list_t *elem;

    if (node != NULL && node->is_child == 0 && node->left != NULL) {
        update_recussiv_path(node->left, pad, list);
    }
    if (node != NULL && node->is_child == 0 && node->right != NULL) {
        update_recussiv_path(node->right, pad, list);
    }
    if (node != NULL && node->is_child == 1) {
        elem = list_t_get_index(list, node->c);
        elem->path = elem->path << 1;
        elem->path += pad;
        elem->nb_bit += 1;
    }
}

static void reverse_recussiv_path(node_t *node, list_t *list)
{
    list_t *elem;
    char tmp = 0;

    if (node != NULL && node->is_child == 0 && node->left != NULL) {
        reverse_recussiv_path(node->left, list);
    }
    if (node != NULL && node->is_child == 0 && node->right != NULL) {
        reverse_recussiv_path(node->right, list);
    }
    if (node != NULL && node->is_child == 1) {
        elem = list_t_get_index(list, node->c);
        for (int i = 0; i < elem->nb_bit; i++) {
            tmp = tmp << 1;
            tmp += elem->path & 1;
            elem->path = elem->path >> 1;
        }
        elem->path = tmp;
    }
}

void init_tree_list(node_t **node, list_t **list, fs_content_t *cont)
{
    node_t *node_left;
    node_t *node_right;
    node_t *tmp;

    fill_node_list(node, list, cont);
    while (node_t_as_list_len(*node) != 1) {
        node_right = node_t_as_list_pop_less(node);
        update_recussiv_path(node_right, 1, *list);
        node_left = node_t_as_list_pop_less(node);
        update_recussiv_path(node_left, 0, *list);
        tmp = node_t_as_node_create_from(node_left, node_right);
        *node = node_t_as_list_add_node(*node, tmp);
    }
    reverse_recussiv_path(*node, *list);
}
