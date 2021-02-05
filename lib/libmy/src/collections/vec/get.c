/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Vec get method
*/

#include "my/my.h"
#include "my/collections/vec.h"

OPT(ptr) vec_get(const vec_t *self, usize_t i)
{
    if (i >= self->len)
        return (NONE(ptr));
    return (SOME(ptr, self->data[i]));
}
