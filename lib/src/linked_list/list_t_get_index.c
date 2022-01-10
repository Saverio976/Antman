/*
** EPITECH PROJECT, 2022
** ANTMAN
** File description:
** get list_t * correspond to index
*/

#include <stddef.h>
#include "linked_list.h"

list_t *list_t_get_index(list_t *list, unsigned int index)
{
    list_t *cursor;

    if (list == NULL) {
        return (NULL);
    }
    cursor = list->next;
    for (; cursor->index != index && cursor != list; cursor = cursor->next);
    if (cursor == list) {
        return (NULL);
    } else {
        return (cursor);
    }
}
