/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Vec find method
*/

#include "my/my.h"
#include "my/collections/vec.h"

OPT(ptr) vec_find_with(vec_t *self, vec_find_fn_t *fn, void *value)
{
    for (usize_t i = 0; i < self->len; i++)
        if (fn ? fn(value, self->data[i]) : (self->data[i] == value))
            return (SOME(ptr, self->data[i]));
    return (NONE(ptr));
}

OPT(ptr) vec_find(vec_t *self, void *element)
{
    return (vec_find_with(self, NULL, element));
}
