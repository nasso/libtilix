/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** vec_clear
*/

#include "my/my.h"
#include "my/collections/vec.h"

void vec_clear(vec_t *self)
{
    self->len = 0;
}

void vec_clear_with(vec_t *self, vec_iter_fn_t *destroyer, void *user_data)
{
    if (destroyer != NULL)
        vec_for_each(self, destroyer, user_data);
    self->len = 0;
}
