/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** my_sstr_cmp implementation
*/

#include "my/my.h"
#include "my/sstr.h"

i32_t my_sstr_cmp(sstr_t self, sstr_t other)
{
    i32_t diff = 0;

    if (self.ptr == other.ptr && self.len == other.len)
        return (0);
    for (usize_t i = 0; i < self.len || i < other.len; i++) {
        diff = i >= self.len ? '\0' : self.ptr[i];
        diff -= i >= other.len ? '\0' : other.ptr[i];
        if (diff != 0)
            return (diff);
    }
    return (0);
}
