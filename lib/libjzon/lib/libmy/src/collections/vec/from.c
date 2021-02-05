/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Vec from_* constructors
*/

#include "my/my.h"
#include "my/collections/vec.h"

vec_t *vec_from_arr(usize_t count, void **data)
{
    vec_t *self = vec_with_capacity(count);

    if (vec_add_arr(self, count, data)) {
        vec_destroy(self);
        return (NULL);
    }
    return (self);
}

vec_t *vec_from_var(usize_t count, va_list ap)
{
    vec_t *self = vec_with_capacity(count);

    if (vec_add_var(self, count, ap)) {
        vec_destroy(self);
        return (NULL);
    }
    return (self);
}

vec_t *vec_from(usize_t count, ...)
{
    vec_t *self = NULL;
    va_list ap;

    va_start(ap, count);
    self = vec_from_var(count, ap);
    va_end(ap);
    return (self);
}
