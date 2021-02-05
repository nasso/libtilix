/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** vector_for_each implementation
*/

#include <stdlib.h>
#include "my/collections/vector.h"

void vector_for_each(vector_t *self, vector_for_each_fn_t *cb,
    void *user_data)
{
    for (size_t i = 0; i < self->len; i++)
        if ((*cb)(user_data, vector_get(self, i)))
            return;
}
