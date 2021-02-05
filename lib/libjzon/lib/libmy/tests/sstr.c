/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Unit tests for sub strings
*/

#include <criterion/criterion.h>
#include "my/my.h"

Test(sstr, my_sstr)
{
    const char *str = "Hello!";
    sstr_t slice = my_sstr(str);

    cr_assert_eq(str, slice.ptr);
    cr_assert_eq(my_cstrlen(str), slice.len);
}

Test(sstr, eq)
{
    cr_assert(my_sstr_eq(my_sstr("hello"), my_sstr("hello")));
}

Test(sstr, cmp)
{
    cr_assert_eq(
        my_cstrcmp("hello", "hello world!"),
        my_sstr_cmp(my_sstr("hello"), my_sstr("hello world!"))
    );
}

Test(sstr, clone)
{
    char *str = my_sstr_clone(my_sstr("hello"));

    cr_assert_str_eq(str, "hello");
    my_free(str);
}

Test(sstr, sub)
{
    cr_assert(my_sstr_eq(my_sstr_sub(my_sstr("hello"), 2, 3), my_sstr("llo")));
    cr_assert(my_sstr_eq(my_sstr_sub(my_sstr("hello"), 2, 8), my_sstr("llo")));
    cr_assert(my_sstr_eq(my_sstr_sub(my_sstr("hello"), 2, -1), my_sstr("llo")));
    cr_assert(my_sstr_eq(my_sstr_sub(my_sstr("hello"), 48, 0), my_sstr("")));
}
