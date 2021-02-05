/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Vec constructors
*/

#include "my/my.h"
#include "my/collections/vec.h"

vec_t *vec_new(void)
{
    return (vec_with_capacity(32));
}

vec_t *vec_with_capacity(usize_t capacity)
{
    vec_t *self = my_calloc(1, sizeof(vec_t));

    if (self == NULL)
        return (NULL);
    self->data = my_malloc(capacity * sizeof(void*));
    if (self->data == NULL) {
        my_free(self);
        return (NULL);
    }
    self->capacity = capacity;
    self->len = 0;
    return (self);
}
