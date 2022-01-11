/*
** EPITECH PROJECT, 2022
** ANTMAN
** File description:
** parsing files
*/

#include <stdlib.h>
#include "linked_list.h"
#include "my_puts.h"

static void set_word_value(char *word, char *buff, int word_len, list_t **list)
{
    int eof = (!buff[1]) ? 1 : 0;
    list_t *found = 0;

    word = malloc(sizeof(char) * (word_len + eof + 1));

    for (int i = 0; buff[i] && i < word_len + eof; i++)
        word[i] = buff[i];
    word[word_len + eof] = '\0';

    found = list_t_contains(*list, word);
    if (!found) {
        *list = list_t_add(*list, word);
        (*list)->frequency++;
    } else {
        found->frequency++;
    }
}

static int get_nb_spaces(char *buffer)
{
    int nb_spaces = 0;

    for (; buffer[nb_spaces] && buffer[nb_spaces] == ' '; nb_spaces++);
    return (nb_spaces);
}

static void take_word_space(int nb_spaces, char *buffer, int *i, list_t **list)
{
    char *word = NULL;

    if (nb_spaces <= 1) {
        return;
    }
    word = malloc(sizeof(char) * (nb_spaces + 1));
    set_word_value(word, &buffer[*i], nb_spaces, list);
    *list = list_t_add(*list, word);
    *i += nb_spaces - 1;
}

list_t *print_dico(list_t *head)
{
    list_t *current = head->next;

    while (current != head) {
        my_printf("%s", current->word);
        if (current->next != head)
            my_printf("@");
        current = current->next;
    }
    return (head);
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
            set_word_value(word, &buffer[i - word_len], word_len, &list);
            my_printf("current last word = %s\n", list->prev->word);
            word_len = 0;
            take_word_space(nb_spaces, buffer, &i, &list);
        } else {
            word_len++;
        }
    }
    if (list->next == list) {
        list->frequency -= 1;
    }
    return (print_dico(list));
}
