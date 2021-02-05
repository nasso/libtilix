/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Vec add methods
*/

#include "my/my.h"
#include "my/collections/vec.h"

bool vec_add_all(vec_t *self, usize_t count, ...)
{
    bool err = false;
    va_list ap;

    va_start(ap, count);
    err = vec_add_var(self, count, ap);
    va_end(ap);
    return (err);
}

bool vec_add_var(vec_t *self, usize_t count, va_list ap)
{
    bool err = false;
    void *val = NULL;

    err = vec_reserve(self, count);
    while (count--) {
        val = va_arg(ap, void*);
        err = err || vec_push(self, val);
    }
    return (err);
}

bool vec_add_arr(vec_t *self, usize_t count, void **data)
{
    if (vec_reserve(self, count))
        return (true);
    for (usize_t i = 0; i < count; i++)
        if (vec_push(self, data[i]))
            return (true);
    return (false);
}

bool vec_add_vec(vec_t *self, const vec_t *other)
{
    if (vec_reserve(self, other->len))
        return (true);
    for (usize_t i = 0; i < other->len; i++)
        if (vec_push(self, other->data[i]))
            return (true);
    return (false);
}
