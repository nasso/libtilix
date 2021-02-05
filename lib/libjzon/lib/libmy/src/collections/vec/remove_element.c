/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Vec remove_element method
*/

#include "my/my.h"
#include "my/collections/vec.h"

OPT(ptr) vec_remove_element(vec_t *self, void *user_data, vec_find_fn_t *fn)
{
    for (usize_t i = 0; i < self->len; i++)
        if (fn ? fn(user_data, self->data[i]) : user_data == self->data[i])
            return (vec_remove(self, i));
    return (NONE(ptr));
}
