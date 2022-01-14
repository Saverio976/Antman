/*
** EPITECH PROJECT, 2022
** ANTMAN
** File description:
** create a child node
*/

#include <stdlib.h>
#include "binary_tree.h"

node_t *node_t_create_child(char c)
{
    node_t *new = malloc(sizeof(node_t));

    if (new == NULL) {
        return (NULL);
    }
    new->c = c;
    new->fat = 0;
    new->is_child = 1;
    return (new);
}
