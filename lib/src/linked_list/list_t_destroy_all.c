/*
** EPITECH PROJECT, 2022
** ANTMAN
** File description:
** destroy all the linked list
*/

#include <stdlib.h>
#include "linked_list.h"

void list_t_destroy_all(list_t *list)
{
    list_t *cursor;
    list_t *tmp;

    if (list == NULL) {
        return;
    }
    cursor = list->next;
    while (cursor != NULL && cursor != list) {
        tmp = cursor->next;
        free(cursor);
        cursor = tmp;
    }
    if (cursor) {
        free(cursor);
    }
}
