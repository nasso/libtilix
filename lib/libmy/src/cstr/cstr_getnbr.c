/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Parses an integer.
*/

#include "my/cstr.h"

i32_t my_cstr_getnbr(const char *str)
{
    return (my_cstr_getnbr_base(str, "0123456789"));
}
