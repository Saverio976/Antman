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
    unsigned char c;
    int is_child;
    int fat;
    node_t *left;
    node_t *right;
    node_t *next;
};

node_t *node_t_as_list_add_char(node_t *list, unsigned char c);

node_t *node_t_as_list_add_node(node_t *list, node_t *node);

node_t *node_t_as_list_pop_less(node_t **list);

node_t *node_t_as_node_create_from(node_t *node_left, node_t *node_right);

node_t *node_t_as_list_contains(node_t *list, unsigned char c);

void node_t_as_node_destroy_all(node_t *node);

int node_t_as_node_postfix(node_t *node, char delim);

node_t *node_t_as_list_pop_last(node_t **list);

node_t *node_t_as_node_from_postfix(char *str, int size, char delim);

int node_t_as_list_len(node_t *list);

#endif
