/*
** EPITECH PROJECT, 2022
** LIBMY
** File description:
** dup n char
*/

#include <stdlib.h>
#include "my_strings.h"

char *my_strndup(char const *str, int n)
{
    char *new;

    new = malloc(sizeof(char) * (n + 1));
    if (new == NULL) {
        return (NULL);
    }
    for (int i = 0; i < n; i++) {
        new[i] = str[i];
    }
    new[n] = '\0';
    return (new);
}
