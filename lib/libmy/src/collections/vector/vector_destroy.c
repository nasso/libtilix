/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Vector destroyers
*/

#include "my/my.h"
#include "my/collections/vector.h"

void vector_destroy(vector_t *self)
{
    if (self == NULL)
        return;
    my_free(self->data);
    my_free(self);
}

void vector_destroy_with(vector_t *self, vector_for_each_fn_t *cb,
    void *user_data)
{
    if (self == NULL)
        return;
    vector_for_each(self, cb, user_data);
    vector_destroy(self);
}
