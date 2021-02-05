/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Vec set method
*/

#include "my/my.h"
#include "my/collections/vec.h"

OPT(ptr) vec_set(vec_t *self, usize_t i, void *data)
{
    void *old_val = NULL;

    if (i >= self->len)
        return (NONE(ptr));
    old_val = self->data[i];
    self->data[i] = data;
    return (SOME(ptr, old_val));
}
