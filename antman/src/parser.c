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

    for (int i = 0; buff[i] && i < word_len; i++)
        word[i] = buff[i];
    word[word_len] = '\0';
}

static int get_nb_spaces(char *buffer)
{
    int nb_spaces = 0;

    for (; buffer[nb_spaces] && buffer[nb_spaces] == ' '; nb_spaces++);
    return (nb_spaces);
}

list_t *launch_parsing(char *buffer)
{
    int word_len = 0;
    char *word = NULL;
    list_t *list = NULL;
    int nb_spaces = 0;

    for (int i = 0; buffer[i]; i++) {
        nb_spaces = get_nb_spaces(&buffer[i]);
        if (nb_spaces || !buffer[i + 1]) {
            word = malloc(sizeof(char) * (word_len + 1));
            get_word_value(word, &buffer[i - word_len], word_len);
            list = list_t_add(list, word);
            word_len = 0;
            if (nb_spaces > 1) {
                word = malloc(sizeof(char) * (nb_spaces + 1));
                get_word_value(word, &buffer[i], nb_spaces);
                list = list_t_add(list, word);
                i += nb_spaces - 1;
            }
        } else {
            word_len++;
        }
    }
    return (list);
}
