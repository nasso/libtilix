/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** 16 bit endianness conversions
*/

#include "my/mem.h"

u16_t u16_ne_to_be(u16_t ne)
{
    if (my_is_big_endian())
        return (ne);
    return (u16_swap_endian(ne));
}

u16_t u16_ne_to_le(u16_t ne)
{
    if (my_is_little_endian())
        return (ne);
    return (u16_swap_endian(ne));
}

u16_t u16_be_to_ne(u16_t be)
{
    if (my_is_big_endian())
        return (be);
    return (u16_swap_endian(be));
}

u16_t u16_le_to_ne(u16_t le)
{
    if (my_is_little_endian())
        return (le);
    return (u16_swap_endian(le));
}
