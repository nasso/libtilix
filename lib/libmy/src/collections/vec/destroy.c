/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Vec destroyer
*/

#include "my/my.h"
#include "my/collections/vec.h"

void vec_destroy(vec_t *self)
{
    if (self == NULL)
        return;
    my_free(self->data);
    my_free(self);
}

void vec_destroy_with(vec_t *self, vec_iter_fn_t *destroyer, void *user_data)
{
    if (self == NULL)
        return;
    if (destroyer != NULL)
        vec_for_each(self, destroyer, user_data);
    vec_destroy(self);
}
