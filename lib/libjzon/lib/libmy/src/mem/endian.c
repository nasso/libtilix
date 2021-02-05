/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Endianness detection
*/

#include "my/mem.h"

bool my_is_little_endian(void)
{
    i32_t x = 1;
    i8_t *c = (i8_t*) &x;

    return ((i32_t) *c);
}

bool my_is_big_endian(void)
{
    i32_t x = 1;
    i8_t *c = (i8_t*) &x;

    return (!((i32_t) *c));
}
