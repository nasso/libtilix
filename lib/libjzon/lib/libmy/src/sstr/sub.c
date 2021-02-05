/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** my_sstr_sub implementation
*/

#include "my/my.h"
#include "my/sstr.h"

sstr_t my_sstr_sub(sstr_t self, usize_t from, usize_t len)
{
    len = usize_min(len, self.len - from);
    return ((sstr_t) { .ptr = self.ptr + from, .len = len });
}
