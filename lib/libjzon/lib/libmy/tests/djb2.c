/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** djb2 algorithm tests
*/

#include <criterion/criterion.h>
#include "my/hash.h"

Test(djb2, basic_hash)
{
    cr_assert_eq(my_djb2("", 0), 0x1505);
    cr_assert_eq(my_djb2("goat", 0), 0x1505);
    cr_assert_eq(my_djb2("goat", 4), 0x17c976fb0);
}

Test(djb2_cstr, cstring_hash)
{
    cr_assert_eq(my_djb2_cstr(""), 0x1505);
    cr_assert_eq(my_djb2_cstr("goat"), 0x17c976fb0);
}
