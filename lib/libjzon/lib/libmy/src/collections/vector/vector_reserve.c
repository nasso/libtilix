/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** vector_reserve implementation
*/

#include <stddef.h>
#include "my/my.h"
#include "my/collections/vector.h"

static const size_t GROW_CHUNK_SIZE = 32;

static size_t max(size_t a, size_t b)
{
    return (a > b ? a : b);
}

int vector_reserve(vector_t *self, size_t additional)
{
    void *data = NULL;
    size_t new_cap = 0;

    if (self->capacity - self->len >= additional)
        return (0);
    new_cap = max(self->capacity + GROW_CHUNK_SIZE, self->len + additional);
    data = my_malloc(self->stride * new_cap);
    if (data == NULL)
        return (1);
    self->capacity = new_cap;
    my_memmove(data, self->data, self->stride * self->len);
    my_free(self->data);
    self->data = data;
    return (0);
}
