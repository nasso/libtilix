/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Vec push method
*/

#include "my/my.h"
#include "my/collections/vec.h"

bool vec_push(vec_t *self, void *data)
{
    if (vec_reserve(self, 1))
        return (true);
    self->data[self->len] = data;
    self->len++;
    return (false);
}
