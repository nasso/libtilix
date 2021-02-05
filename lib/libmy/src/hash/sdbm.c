/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** sdbm hashing algorithm
*/

#include "my/my.h"

u64_t my_sdbm(const void *raw_data, usize_t n)
{
    const u8_t *data = (const u8_t*) raw_data;
    u64_t hash = 0;

    for (usize_t i = 0; i < n; i++)
        hash = data[i] + (hash << 6) + (hash << 16) - hash;
    return (hash);
}

u64_t my_sdbm_cstr(const char *str)
{
    u64_t hash = 0;

    for (usize_t i = 0; str[i]; i++)
        hash = str[i] + (hash << 6) + (hash << 16) - hash;
    return (hash);
}
