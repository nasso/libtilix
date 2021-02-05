/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Vec remove method
*/

#include "my/my.h"
#include "my/collections/vec.h"

OPT(ptr) vec_remove(vec_t *self, usize_t i)
{
    usize_t moved = self->len - i - 1;
    void *val = NULL;

    if (i >= self->len)
        return (NONE(ptr));
    val = self->data[i];
    self->len--;
    my_memmove(&self->data[i], &self->data[i + 1], moved * sizeof(void*));
    return (SOME(ptr, val));
}

OPT(ptr) vec_swap_remove(vec_t *self, usize_t i)
{
    void *val = NULL;

    if (i >= self->len)
        return (NONE(ptr));
    val = self->data[i];
    self->data[i] = self->data[self->len - 1];
    self->len--;
    return (SOME(ptr, val));
}
