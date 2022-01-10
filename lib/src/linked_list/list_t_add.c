/*
** EPITECH PROJECT, 2022
** ANTMAN
** File description:
** add char * to list
*/

#include <stdlib.h>
#include "linked_list.h"

list_t *list_t_add(list_t *list, char *data)
{
    list_t *new = malloc(sizeof(list_t));

    if (new == NULL) {
        return (NULL);
    }
    new->word = data;
    if (list == NULL) {
        new->prev = new;
        new->next = new;
        new->index = 0;
        return (new);
    }
    new->prev = list->prev;
    new->next = list;
    new->index = list->prev->index + 1;
    list->prev->next = new;
    list->prev = new;
    return (new);
}
