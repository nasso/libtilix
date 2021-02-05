/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** vector_push and vector_pop implementations
*/

#include <stdlib.h>
#include "my/collections/vector.h"

int vector_push(vector_t *self, const void *element)
{
    if (vector_reserve(self, 1))
        return (-1);
    self->len++;
    vector_set(self, self->len - 1, element);
    return (0);
}

void *vector_pop(vector_t *self)
{
    void *element = NULL;

    if (self->len > 0) {
        element = vector_get(self, self->len - 1);
        self->len--;
    }
    return (element);
}
