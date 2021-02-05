/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** vector_remove and vector_swap_remove
*/

#include <stdlib.h>
#include "my/my.h"
#include "my/collections/vector.h"

void vector_remove(vector_t *self, size_t index, void *elem_out)
{
    size_t stride = self->stride;
    size_t left = self->len - index;
    char *data = self->data;

    if (self->len == 0)
        return;
    if (elem_out != NULL)
        my_memmove(elem_out, vector_get(self, index), stride);
    my_memmove(data + index * stride, data + (index + 1) * stride, left);
    self->len--;
}
