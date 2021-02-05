/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** my_sstr implementation
*/

#include "my/my.h"
#include "my/sstr.h"

sstr_t my_sstr(const char *cstr)
{
    return ((sstr_t) { .ptr = cstr, .len = my_cstrlen(cstr) });
}
