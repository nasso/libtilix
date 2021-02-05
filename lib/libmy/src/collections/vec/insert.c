/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Vec insert method
*/

#include "my/my.h"
#include "my/collections/vec.h"

bool vec_insert(vec_t *self, usize_t i, void *data)
{
    usize_t moved = self->len - i;

    if (i >= self->len || vec_reserve(self, 1))
        return (true);
    my_memmove(&self->data[i + 1], &self->data[i], moved * sizeof(void*));
    self->data[i] = data;
    self->len++;
    return (false);
}
