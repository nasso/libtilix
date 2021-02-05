/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** vector_get and vector_set implementations
*/

#include <stdlib.h>
#include "my/my.h"
#include "my/collections/vector.h"

void *vector_get(const vector_t *self, size_t index)
{
    char *data = self->data;

    return (&data[self->stride * index]);
}

void vector_set(vector_t *self, size_t index, const void *element)
{
    void *dest = vector_get(self, index);

    my_memmove(dest, element, self->stride);
}
