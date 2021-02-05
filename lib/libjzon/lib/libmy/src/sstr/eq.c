/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** my_sstr_eq implementation
*/

#include "my/my.h"
#include "my/sstr.h"

bool my_sstr_eq(sstr_t self, sstr_t other)
{
    if (self.len != other.len)
        return (false);
    if (self.ptr == other.ptr)
        return (true);
    for (usize_t i = 0; i < self.len; i++)
        if (self.ptr[i] != other.ptr[i])
            return (false);
    return (true);
}
