/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_sstr_find implementation
*/

#include "my/my.h"
#include "my/sstr.h"

OPT(sstr) my_sstr_find(sstr_t self, sstr_t other)
{
    if (self.len < other.len)
        return (NONE(sstr));
    if (other.len == 0)
        return (SOME(sstr, my_sstr_sub(self, 0, 0)));
    for (usize_t i = 0; i + other.len <= self.len; i++)
        if (!my_sstr_eq(my_sstr_sub(self, i, other.len), other))
            return (SOME(sstr, my_sstr_sub(self, i, other.len)));
    return (NONE(sstr));
}
