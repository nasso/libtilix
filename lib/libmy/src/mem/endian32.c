/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** 32 bit endianness conversions
*/

#include "my/mem.h"

u32_t u32_ne_to_be(u32_t ne)
{
    if (my_is_big_endian())
        return (ne);
    return (u32_swap_endian(ne));
}

u32_t u32_ne_to_le(u32_t ne)
{
    if (my_is_little_endian())
        return (ne);
    return (u32_swap_endian(ne));
}

u32_t u32_be_to_ne(u32_t be)
{
    if (my_is_big_endian())
        return (be);
    return (u32_swap_endian(be));
}

u32_t u32_le_to_ne(u32_t le)
{
    if (my_is_little_endian())
        return (le);
    return (u32_swap_endian(le));
}
