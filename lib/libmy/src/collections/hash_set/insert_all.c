/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** hash_set_insert_all_* functions
*/

#include <stdarg.h>
#include "my/my.h"
#include "my/collections/hash_set.h"

bool hash_set_insert_all(hash_set_t *self, usize_t count, ...)
{
    bool err = false;
    va_list ap;

    va_start(ap, count);
    err = hash_set_insert_all_var(self, count, ap);
    va_end(ap);
    return (err);
}

bool hash_set_insert_all_var(hash_set_t *self, usize_t count, va_list ap)
{
    bool err = false;
    void *data = NULL;

    for (usize_t i = 0; !err && i < count; i++) {
        data = va_arg(ap, void*);
        err = hash_set_insert(self, data);
    }
    return (err);
}

bool hash_set_insert_all_arr(hash_set_t *self, usize_t n, void *const *arr)
{
    bool err = false;

    for (usize_t i = 0; !err && i < n; i++)
        err = hash_set_insert(self, arr[i]);
    return (err);
}
