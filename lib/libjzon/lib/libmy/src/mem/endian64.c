/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** 64 bit endianness conversions
*/

#include "my/mem.h"

u64_t u64_ne_to_be(u64_t ne)
{
    if (my_is_big_endian())
        return (ne);
    return (u64_swap_endian(ne));
}

u64_t u64_ne_to_le(u64_t ne)
{
    if (my_is_little_endian())
        return (ne);
    return (u64_swap_endian(ne));
}

u64_t u64_be_to_ne(u64_t be)
{
    if (my_is_big_endian())
        return (be);
    return (u64_swap_endian(be));
}

u64_t u64_le_to_ne(u64_t le)
{
    if (my_is_little_endian())
        return (le);
    return (u64_swap_endian(le));
}
