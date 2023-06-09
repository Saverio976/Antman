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

static unsigned char *get_only_compressed(header_t *head, fs_content_t *cont,
    long int *size_compress)
{
    unsigned char *compress;
    long int size;

    if (cont == NULL) {
        return (NULL);
    }
    if (head->dico_size == 0 && head->size_minus_byte == 0) {
        return (NULL);
    }
    size = cont->size - sizeof(header_t) - head->dico_size;
    compress = my_strndup(cont->content + head->dico_size, size);
    *size_compress = size;
    return (compress);
}

int starter_main(char const *file, __attribute__((unused)) int type)
{
    fs_content_t *buff;
    header_t head;
    unsigned char *compress;
    node_t *tree;
    long int size_compressed = 0;

    buff = fs_get_content(file);
    if (buff == NULL)
        return (84);
    head = read_header(file);
    compress = get_only_compressed(&head, buff, &size_compressed);
    if (compress == NULL) {
        return (84);
    }
    tree = node_t_as_node_from_postfix(buff->content, head.dico_size, '\0');
    decode_str(compress, tree, head.size_minus_byte, size_compressed);
    fs_content_t_free(buff);
    free(compress);
    return (0);
}
