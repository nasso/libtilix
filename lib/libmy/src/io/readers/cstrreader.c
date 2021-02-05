/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** cstrreader implementation
*/

#include "my/my.h"
#include "my/io/cstrreader.h"

struct reader_data {
    const char *str;
    usize_t size;
};

static OPT(usize) read_cb(void *ptr, void *buffer, usize_t n)
{
    struct reader_data *self = ptr;

    if (self->size == 0)
        return (NONE(usize));
    n = usize_min(n, self->size);
    my_memcpy(buffer, self->str, n * sizeof(char));
    self->size -= n;
    self->str += n;
    return (SOME(usize, n));
}

bufreader_t *cstrreader_new(const char *str, usize_t bufsize)
{
    struct reader_data *self = my_malloc(sizeof(struct reader_data));
    bufreader_t *br = NULL;

    if (self == NULL)
        return (NULL);
    br = bufreader_new(bufsize);
    if (br == NULL) {
        my_free(self);
        return (NULL);
    }
    self->str = str;
    self->size = my_cstrlen(str);
    br->user_data = self;
    br->read_cb = &read_cb;
    br->free_cb = &my_free;
    return (br);
}
