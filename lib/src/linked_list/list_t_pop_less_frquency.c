/*
** EPITECH PROJECT, 2022
** ANTMAN
** File description:
** pop the less
*/

#include <stddef.h>
#include "linked_list.h"

static list_t *get_less_frequency(list_t *list)
{
    list_t *cursor = list->next;
    list_t *tmp = cursor;

    for (; cursor != NULL && cursor != list->next; cursor = cursor->next) {
        if (tmp->frequency > cursor->frequency) {
            tmp = cursor;
        }
    }
    return (tmp);
}

list_t *list_t_pop_less_frequency(list_t **elem)
{
    list_t *next;
    list_t *prev;
    list_t *cursor;

    if (*elem == NULL) {
        return NULL;
    }
    cursor = get_less_frequency(*elem);
    if (cursor == *elem) {
        (*elem) = (*elem)->next;
    } else {
        next = (*elem)->next;
        prev = (*elem)->prev;
        next->prev = prev;
        prev->next = next;
    }
    return (cursor);
}
