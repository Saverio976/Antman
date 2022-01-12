/*
** EPITECH PROJECT, 2022
** ANTMAN
** File description:
** create a binary tree
*/

#ifndef BINARY_TREE_H_
    #define BINARY_TREE_H_

typedef struct binary_tree_t binary_tree_t;
typedef struct node_t node_t;

struct binary_tree_t {
    node_t *first;
    node_t *priv_cursor;
};

struct node_t {
    char c;
    int is_child;
    node_t *left;
    node_t *right;
};

binary_tree_t *binary_tree_t_create(void);

binary_tree_t *binary_tree_t_push_huffman(binary_tree_t *, char);

void binary_tree_t_to_infix(binary_tree_t *);

binary_tree_t *binary_tree_t_from_infix(const char *, int);

void binary_tree_t_destroy(binary_tree_t *);

#endif
