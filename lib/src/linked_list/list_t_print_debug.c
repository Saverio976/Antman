/*
** EPITECH PROJECT, 2022
** ANTMAN
** File description:
** debug print all elem in list
*/

#include <stddef.h>
#include "my_puts.h"
#include "linked_list.h"

void list_t_print_debug(list_t *list)
{
    list_t *cursor = list;

    if (list == NULL) {
        return;
    }
    my_printf("list[%d] = '%s'\n", list->index, list->word);
    cursor = list->next;
    while (cursor != NULL && cursor != list) {
        my_printf("list[%d] = '%s'\n", list->index, list->word);
        cursor = cursor->next;
    }
}
