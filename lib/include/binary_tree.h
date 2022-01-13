/*
** EPITECH PROJECT, 2022
** ANTMAN
** File description:
** create a binary tree
*/

#ifndef BINARY_TREE_H_
    #define BINARY_TREE_H_

typedef struct node_t node_t;

struct node_t {
    char c;
    int is_child;
    int fat;
    node_t *left;
    node_t *right;
    node_t *prev;
    node_t *next;
};

node_t *node_t_as_list_add_char(node_t *list, char c);

node_t *node_t_as_list_add_node(node_t *list, node_t *node);

node_t *node_t_as_node_create_from(node_t *node_left, node_t *node_right);

node_t *node_t_as_list_pop_less(node_t *list);



#endif
