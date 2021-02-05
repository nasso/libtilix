/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** hash_set_from_* functions
*/

#include <stdarg.h>
#include "my/my.h"
#include "my/collections/hash_set.h"

hash_set_t *hash_set_from(hash_set_hash_fn_t *fn, usize_t count, ...)
{
    hash_set_t *self = NULL;
    va_list ap;

    va_start(ap, count);
    self = hash_set_from_var(fn, count, ap);
    va_end(ap);
    return (self);
}

hash_set_t *hash_set_from_var(hash_set_hash_fn_t *fn, usize_t count, va_list ap)
{
    hash_set_t *self = hash_set_new(fn);

    if (self == NULL)
        return (NULL);
    hash_set_insert_all_var(self, count, ap);
    return (self);
}

hash_set_t *hash_set_from_arr(hash_set_hash_fn_t *fn, usize_t n,
    void *const *arr)
{
    hash_set_t *self = hash_set_new(fn);

    if (self == NULL)
        return (NULL);
    hash_set_insert_all_arr(self, n, arr);
    return (self);
}
