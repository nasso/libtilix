/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Memory utils
*/

#ifndef LIBMY_MEM_H
#define LIBMY_MEM_H

#include "my/types.h"

void *my_malloc(usize_t size);
void my_free(void *ptr);
void *my_calloc(usize_t nmemb, usize_t size);
void *my_memset(void *s, u8_t c, usize_t n);
void *my_memmove(void *dest, const void *src, usize_t n);
void *my_memcpy(void *dest, const void *src, usize_t n);
bool my_is_big_endian(void);
bool my_is_little_endian(void);
u16_t u16_ne_to_be(u16_t);
u16_t u16_ne_to_le(u16_t);
u32_t u32_ne_to_be(u32_t);
u32_t u32_ne_to_le(u32_t);
u64_t u64_ne_to_be(u64_t);
u64_t u64_ne_to_le(u64_t);
u16_t u16_be_to_ne(u16_t);
u16_t u16_le_to_ne(u16_t);
u32_t u32_be_to_ne(u32_t);
u32_t u32_le_to_ne(u32_t);
u64_t u64_be_to_ne(u64_t);
u64_t u64_le_to_ne(u64_t);

static inline u16_t u16_swap_endian(u16_t val)
{
    return (
        ((val >> 8) & 0x00FF) |
        ((val << 8) & 0xFF00)
    );
}

static inline u32_t u32_swap_endian(u32_t val)
{
    return (
        ((val >> 24) & 0x000000FF) |
        ((val >> 8) & 0x0000FF00) |
        ((val << 8) & 0x00FF0000) |
        ((val << 24) & 0xFF000000)
    );
}

static inline u64_t u64_swap_endian(u64_t val)
{
    return (
        ((val >> 56) & 0x00000000000000FF) |
        ((val >> 40) & 0x000000000000FF00) |
        ((val >> 24) & 0x0000000000FF0000) |
        ((val >> 8) & 0x00000000FF000000) |
        ((val << 8) & 0x000000FF00000000) |
        ((val << 24) & 0x0000FF0000000000) |
        ((val << 40) & 0x00FF000000000000) |
        ((val << 56) & 0xFF00000000000000)
    );
}

#endif /* LIBMY_MEM_H */
