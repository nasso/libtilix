/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** sdbm algorithm tests
*/

#include <criterion/criterion.h>
#include "my/hash.h"

Test(sdbm, basic_hash)
{
    cr_assert_eq(my_sdbm("", 0), 0x0);
    cr_assert_eq(my_sdbm("goat", 0), 0x0);
    cr_assert_eq(my_sdbm("goat", 4), 0x674c8cef47ce1b);
}

Test(sdbm_cstr, cstring_hash)
{
    cr_assert_eq(my_sdbm_cstr(""), 0x0);
    cr_assert_eq(my_sdbm_cstr("goat"), 0x674c8cef47ce1b);
}
