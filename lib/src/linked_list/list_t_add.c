/*
** EPITECH PROJECT, 2022
** ANTMAN
** File description:
** add char * to list
*/

#include <stdlib.h>
#include "linked_list.h"

static void update_link_list(list_t *list, list_t *new)
{
    new->prev = list->prev;
    new->next = list;
    new->index = list->prev->index + 1;
    new->frequency = 0;
    list->prev->next = new;
    list->prev = new;
}

list_t *list_t_add(list_t *list, char *data)
{
    list_t *new;
    list_t *tmp;

    if (list == NULL) {
        new = malloc(sizeof(list_t));
        new->word = data;
        new->prev = new;
        new->next = new;
        new->index = 0;
        return (new);
    }
    tmp = list_t_contains(list, data);
    if (tmp != NULL) {
        tmp->frequency += 1;
    } else {
        new = malloc(sizeof(list_t));
        new->word = data;
        update_link_list(list, new);
    }
    return (list);
}
