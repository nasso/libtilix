/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Hashing algorithms
*/

#ifndef LIBMY_HASH_H
#define LIBMY_HASH_H

#include "my/types.h"

u64_t my_djb2(const void*, usize_t);
u64_t my_djb2_cstr(const char*);
u64_t my_djb2x(const void*, usize_t);
u64_t my_djb2x_cstr(const char*);
u64_t my_sdbm(const void*, usize_t);
u64_t my_sdbm_cstr(const char*);

#endif /* LIBMY_HASH_H */
