/*
** EPITECH PROJECT, 2022
** ANTMAN
** File description:
** the main project header
*/

#ifndef PROJECT_ANTMAN_H_
    #define PROJECT_ANTMAN_H_

    #include "binary_tree.h"

typedef struct header_t header_t;

struct header_t {
    unsigned int dico_size;
    short int size_minus_byte;
};

header_t read_header(char const *path);

void write_header(unsigned int dico_char_size, short int size_minus_byte);

int starter_main(char const *file, int type);

void decode_str(unsigned char *str, node_t *tree, int last_nbyte,
        long int size);

void print_code_c(char c);

#endif
