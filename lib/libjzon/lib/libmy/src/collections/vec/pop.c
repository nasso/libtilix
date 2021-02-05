/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Vec pop method
*/

#include "my/my.h"
#include "my/collections/vec.h"

OPT(ptr) vec_pop(vec_t *self)
{
    if (self->len == 0)
        return (NONE(ptr));
    self->len--;
    return (SOME(ptr, self->data[self->len]));
}
