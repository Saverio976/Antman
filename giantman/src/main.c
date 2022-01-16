/*
** EPITECH PROJECT, 2022
** GIANTMAN
** File description:
** main function
*/

#include <stdlib.h>
#include "my_fs.h"
#include "my_puts.h"
#include "my_strings.h"
#include "project.h"
#include "binary_tree.h"

static char *get_only_compressed(header_t *head, fs_content_t *cont)
{
    char *compress;
    int size;

    if (cont == NULL) {
        return (NULL);
    }
    if (head->dico_size == 0 && head->size_minus_byte == 0) {
        return (NULL);
    }
    size = cont->size - sizeof(header_t) - head->dico_size;
    compress = my_strndup(cont->content + head->dico_size, size);
    return (compress);
}

int starter_main(char const *file, __attribute__((unused)) int type)
{
    fs_content_t *buff;
    header_t head;
    char *compress;
    node_t *tree;

    buff = fs_get_content(file);
    if (buff == NULL)
        return (84);
    head = read_header(file);
    compress = get_only_compressed(&head, buff);
    if (compress == NULL) {
        return (84);
    }
    tree = node_t_as_node_from_postfix(buff->content, head.dico_size, '\0');
    node_t_as_node_postfix(tree, '-');
    fs_content_t_free(buff);
    free(compress);
    return (0);
}
