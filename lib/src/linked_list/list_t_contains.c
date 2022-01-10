/*
** EPITECH PROJECT, 2022
** ANTMAN
** File description:
** check if the list contains an element
*/

#include <stddef.h>
#include "my_strings.h"
#include "linked_list.h"

list_t *list_t_contains(list_t *list, char *data)
{
    list_t *cursor;
    int is_find = 0;

    if (list == NULL) {
        return (NULL);
    }
    cursor = list->next;
    while (cursor != NULL && cursor != list && is_find == 0) {
        if (my_strcmp(cursor->word, data) == 0) {
            is_find = 1;
        } else {
            cursor = cursor->next;
        }
    }
    if (is_find == 1) {
        return (cursor);
    } else {
        return (NULL);
    }
}
