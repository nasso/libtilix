/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Sub-string utils
*/

#ifndef LIBMY_SSTR_H
#define LIBMY_SSTR_H

#include "my/types.h"
#include "my/cstr.h"

typedef struct {
    const char *ptr;
    usize_t len;
} sstr_t;

OPT_DEFINE(sstr_t, sstr)

sstr_t my_sstr(const char *cstr);
sstr_t my_sstr_sub(sstr_t self, usize_t from, usize_t len);
char *my_sstr_clone(sstr_t self);
bool my_sstr_eq(sstr_t self, sstr_t other);
i32_t my_sstr_cmp(sstr_t self, sstr_t other);
OPT(sstr) my_sstr_find(sstr_t self, sstr_t other);

#endif /* LIBMY_SSTR_H */
