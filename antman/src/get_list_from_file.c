/*
** EPITECH PROJECT, 2022
** ANTMAN
** File description:
** get list and frequency
*/

#include <stddef.h>
#include "linked_list.h"

list_t *get_list_from_buff(char *buff, int size)
{
    list_t *list = NULL;

    for (int i = 0; i < size; i++) {
        list = list_t_add(list, buff[i]);
    }
    return (list);
}
