/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** JZON primitives tests
*/

#include <criterion/criterion.h>
#include "my/my.h"
#include "jzon/jzon.h"

Test(primitives, num)
{
    jzon_t jz = jzon_create_num(59);

    cr_assert_eq(jzon_num(jz), 59);
    cr_assert_not(jzon_set_num(jz, 923));
    cr_assert_eq(jzon_num(jz), 923);
    jzon_drop(jz);
}

Test(primitives, str)
{
    jzon_t jz = jzon_create_str("foo");

    cr_assert_str_eq(jzon_str(jz), "foo");
    cr_assert_not(jzon_set_str(jz, "bar"));
    cr_assert_str_eq(jzon_str(jz), "bar");
    jzon_drop(jz);
}

Test(primitives, bool)
{
    jzon_t jz = jzon_create_bool(true);

    cr_assert_eq(jzon_bool(jz), true);
    cr_assert_not(jzon_set_bool(jz, false));
    cr_assert_eq(jzon_bool(jz), false);
    jzon_drop(jz);
}
