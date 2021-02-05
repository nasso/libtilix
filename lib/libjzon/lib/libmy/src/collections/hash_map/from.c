/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** hash_map_from_* functions
*/

#include <stdarg.h>
#include "my/my.h"
#include "my/collections/hash_map.h"

hash_map_t *hash_map_from(usize_t count, ...)
{
    hash_map_t *self = NULL;
    va_list ap;

    va_start(ap, count);
    self = hash_map_from_var(count, ap);
    va_end(ap);
    return (self);
}

hash_map_t *hash_map_from_var(usize_t count, va_list ap)
{
    hash_map_t *self = hash_map_new();

    if (self == NULL)
        return (NULL);
    hash_map_insert_all_var(self, count, ap);
    return (self);
}

hash_map_t *hash_map_from_arr(usize_t n, hash_map_pair_t *arr)
{
    hash_map_t *self = hash_map_new();

    if (self == NULL)
        return (NULL);
    hash_map_insert_all_arr(self, n, arr);
    return (self);
}
