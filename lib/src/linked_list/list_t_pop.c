/*
** EPITECH PROJECT, 2022
** ANTMAN
** File description:
** pop
*/

#include <stdlib.h>
#include "linked_list.h"

static void same_elem_itter(list_t **elem)
{
    free(*elem);
    *elem = NULL;
}

static void not_same_itter(list_t *next, list_t *prev, list_t **elem)
{
    free(*elem);
    next->prev = prev;
    prev->next = next;
}

void list_t_pop(list_t **elem)
{
    list_t *next;
    list_t *prev;

    if (*elem == NULL) {
        return;
    }
    next = (*elem)->next;
    prev = (*elem)->prev;
    if (next == *elem) {
        same_elem_itter(elem);
    } else {
        not_same_itter(next, prev, elem);
    }
}
