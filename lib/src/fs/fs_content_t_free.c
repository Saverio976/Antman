/*
** EPITECH PROJECT, 2022
** ANTMAN
** File description:
** free fs_conttent_t
*/

#include <stdlib.h>
#include "my_fs.h"

void fs_content_t_free(fs_content_t *content)
{
    free(content->content);
    free(content);
}
