/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** option tests
*/

#include <criterion/criterion.h>
#include "my/my.h"

struct my_struct {
    i32_t a;
    i32_t b;
};

OPT_DEFINE(struct my_struct, my_struct)

Test(option, scalars)
{
    OPT(i32) some_int = SOME(i32, 5);
    OPT(i32) none_int = NONE(i32);

    cr_assert(some_int.is_some);
    cr_assert_eq(some_int.v, 5);
    cr_assert_not(none_int.is_some);
}

Test(option, compound_types)
{
    OPT(my_struct) some_struct = SOME(my_struct,
        (struct my_struct) {.a = 15, .b = 35 + 8});
    OPT(my_struct) some_struct2 = SOME(my_struct, (struct my_struct) {-53, 18});
    OPT(my_struct) none_struct = NONE(my_struct);

    cr_assert(some_struct.is_some);
    cr_assert_eq(some_struct.v.a, 15);
    cr_assert_eq(some_struct.v.b, 35 + 8);
    cr_assert(some_struct2.is_some);
    cr_assert_eq(some_struct2.v.a, -53);
    cr_assert_eq(some_struct2.v.b, 18);
    cr_assert_not(none_struct.is_some);
}
