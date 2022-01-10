/*
** EPITECH PROJECT, 2022
** ANTMAN
** File description:
** parsing files
*/

#include <stdlib.h>
#include "linked_list.h"
#include "my_puts.h"

static void get_word_value(char *word, char *buff, int word_len) {

    for (int i = 0; buff[i] && buff[i] != ' '; i++)
        word[i] = buff[i];
    word[word_len] = '\0';
}

list_t *launch_parsing(char *buffer)
{
    int word_len = 0;
    char *word = NULL;
    list_t *list = NULL;

    for (int i = 0; buffer[i]; i++) {
        if (buffer[i] == ' ' || !buffer[i + 1]) {
            word = malloc(sizeof(char) * (word_len + 1));
            get_word_value(word, &buffer[i - word_len], word_len);
            list = list_t_add(list, word);
            word_len = 0;
        } else {
            word_len++;
        }
    }
    return (list);
}
