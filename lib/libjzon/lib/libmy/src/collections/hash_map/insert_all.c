/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** hash_map_insert_all_* functions
*/

#include <stdarg.h>
#include "my/my.h"
#include "my/collections/hash_map.h"

bool hash_map_insert_all(hash_map_t *self, usize_t count, ...)
{
    bool err = false;
    va_list ap;

    va_start(ap, count);
    err = hash_map_insert_all_var(self, count, ap);
    va_end(ap);
    return (err);
}

bool hash_map_insert_all_var(hash_map_t *self, usize_t count, va_list ap)
{
    const char *key = NULL;
    bool err = false;
    void *data = NULL;

    for (usize_t i = 0; !err && i < count; i++) {
        key = va_arg(ap, const char*);
        data = va_arg(ap, void*);
        err |= !hash_map_insert(self, key, data).is_ok;
    }
    return (err);
}

bool hash_map_insert_all_arr(hash_map_t *self, usize_t n, hash_map_pair_t *arr)
{
    bool err = false;

    for (usize_t i = 0; !err && i < n; i++)
        err = !hash_map_insert(self, arr[i].key, arr[i].value).is_ok;
    return (err);
}
