/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** djb2 hashing algorithm
*/

#include "my/my.h"

u64_t my_djb2(const void *raw_data, usize_t n)
{
    const u8_t *data = (const u8_t*) raw_data;
    u64_t hash = 5381;

    for (usize_t i = 0; i < n; i++)
        hash += (hash << 5) + data[i];
    return (hash);
}

u64_t my_djb2_cstr(const char *str)
{
    u64_t hash = 5381;

    for (usize_t i = 0; str[i]; i++)
        hash += (hash << 5) + str[i];
    return (hash);
}

u64_t my_djb2x(const void *raw_data, usize_t n)
{
    const u8_t *data = (const u8_t*) raw_data;
    u64_t hash = 5381;

    for (usize_t i = 0; i < n; i++)
        hash += (hash << 5) ^ data[i];
    return (hash);
}

u64_t my_djb2x_cstr(const char *str)
{
    u64_t hash = 5381;

    for (usize_t i = 0; str[i]; i++)
        hash += (hash << 5) ^ str[i];
    return (hash);
}
