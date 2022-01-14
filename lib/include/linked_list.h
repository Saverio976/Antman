/*
** EPITECH PROJECT, 2022
** ANTMAN
** File description:
** implement a linked list
*/

#ifndef LINKED_LIST_H_
    #define LINKED_LIST_H_

typedef struct list_t list_t;

struct list_t {
    list_t *prev;
    list_t *next;
    unsigned char path;
    int nb_bit;
    unsigned int index;
};

list_t *list_t_add(list_t *, char);

list_t *list_t_get_index(list_t *, unsigned int);

void list_t_print_debug(list_t *);

void list_t_pop(list_t **);

void list_t_destroy_all(list_t *);

#endif
