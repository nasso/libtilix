/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Vec for_each method
*/

#include "my/types.h"
#include "my/collections/vec.h"

OPT(i32) vec_for_each(vec_t *self, vec_iter_fn_t *fn, void *user_data)
{
    OPT(i32) err = NONE(i32);

    for (usize_t i = 0; !err.is_some && i < self->len; i++)
        err = fn(user_data, self->data[i]);
    return (err);
}
