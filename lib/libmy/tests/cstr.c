/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** cstr tests
*/

#include <criterion/criterion.h>
#include <string.h>
#include "my/my.h"
#include "my/cstr.h"

Test(my_cstr_getnbr_base, positive_values)
{
    cr_assert_eq(my_cstr_getnbr_base("42", "0123456789"), 42);
    cr_assert_eq(my_cstr_getnbr_base("0", "0123456789"), 0);
    cr_assert_eq(my_cstr_getnbr_base("2147483647", "0123456789"), 2147483647);
}

Test(my_cstr_getnbr_base, negative_values)
{
    cr_assert_eq(my_cstr_getnbr_base("-42", "0123456789"), -42);
    cr_assert_eq(my_cstr_getnbr_base("---42", "0123456789"), -42);
    cr_assert_eq(my_cstr_getnbr_base("---+---+-42", "0123456789"), -42);
    cr_assert_eq(my_cstr_getnbr_base("-0", "0123456789"), 0);
    cr_assert_eq(my_cstr_getnbr_base("-2147483648", "0123456789"), -2147483648);
}

Test(my_cstr_getnbr_base, junk_values)
{
    cr_assert_eq(my_cstr_getnbr_base("abc", "0123456789"), 0);
    cr_assert_eq(my_cstr_getnbr_base("42gae", "0123456789"), 42);
    cr_assert_eq(my_cstr_getnbr_base("--01s5-601gr", "0123456789"), 1);
}

Test(my_cstr_getnbr_base, other_bases)
{
    cr_assert_eq(my_cstr_getnbr_base("abc", "abc"), 5);
    cr_assert_eq(my_cstr_getnbr_base("E621", "0123456789ABCDEF"), 0xE621);
}

Test(my_cstr_isalpha, return_one_when_alpha)
{
    char *str = "abcdef";

    cr_assert(my_cstr_isalpha(str));
}

Test(my_cstr_isalpha, return_zero_when_not_alpha)
{
    char *str = "abc def";

    cr_assert_not(my_cstr_isalpha(str));
}

Test(my_cstr_isalpha, return_one_when_empty)
{
    char *str = "";

    cr_assert(my_cstr_isalpha(str));
}

Test(my_cstr_islower, return_one_when_lower)
{
    char *str = "abcdef";

    cr_assert(my_cstr_islower(str));
}

Test(my_cstr_islower, return_zero_when_not_lower)
{
    char *str = "abc def";

    cr_assert_not(my_cstr_islower(str));
}

Test(my_cstr_islower, return_one_when_empty)
{
    char *str = "";

    cr_assert(my_cstr_islower(str));
}

Test(my_cstr_isprintable, return_one_when_printable)
{
    char *str = "ABC123";

    cr_assert(my_cstr_isprintable(str));
}

Test(my_cstr_isprintable, return_zero_when_not_printable)
{
    char *str = "ABC\n123";

    cr_assert_not(my_cstr_isprintable(str));
}

Test(my_cstr_isprintable, return_one_when_empty)
{
    char *str = "";

    cr_assert(my_cstr_isprintable(str));
}

Test(my_cstrcat, concats_two_strings)
{
    char dest[16] = "Hello";

    for (int i = 5; i < 16; i++)
        dest[i] = 0;
    my_cstrcat(dest, ", World!");
    cr_assert_str_eq(dest, "Hello, World!");
}

Test(my_cstrdup, empty_string)
{
    cr_assert_str_eq(my_cstrdup(""), "");
}

Test(my_cstrdup, non_empty_string)
{
    cr_assert_str_eq(my_cstrdup("baaa"), "baaa");
}

Test(my_cstrndup, empty_string)
{
    cr_assert_str_eq(my_cstrndup("baaa", 0), "");
}

Test(my_cstrndup, non_empty_string)
{
    cr_assert_str_eq(my_cstrndup("baaa", 2), "ba");
}

Test(my_cstrncat, concats_two_strings_n)
{
    char dest[16] = "Hello";

    for (int i = 5; i < 16; i++)
        dest[i] = 0;
    my_cstrncat(dest, ", World!", 7);
    cr_assert_str_eq(dest, "Hello, World");
}

Test(my_cstrncmp, return_zero_when_equal)
{
    char    *str1 = "Hello World!";
    char    *str2 = "Hello World!";
    int     expected = strncmp(str1, str2, 4);
    int     got = my_cstrncmp(str1, str2, 4);

    cr_assert_eq(got, expected);
}

Test(my_cstrncmp, return_non_zero_when_not_equal)
{
    char    *str1 = "Hello World!";
    char    *str2 = "Hello world!";
    int     expected;
    int     got;

    expected = strncmp(str1, str2, 4);
    got = my_cstrncmp(str1, str2, 4);
    cr_assert_eq(got, expected);
    expected = strncmp(str2, str1, 4);
    got = my_cstrncmp(str2, str1, 4);
    cr_assert_eq(got, expected);
}

Test(my_cstrncpy, copy_five_characters_in_empty_array)
{
    char    dest[6] = {0};

    my_cstrncpy(dest, "HelloWorld", 5);
    cr_assert_str_eq(dest, "Hello");
}

Test(my_cstrncpy, copy_string_in_empty_array)
{
    char    my_dest[6] = {0};
    char    dest[6] = {0};

    my_cstrncpy(my_dest, "Hello", 6);
    strncpy(dest, "Hello", 6);
    cr_assert_str_eq(my_dest, dest);
}

Test(my_cstrncpy, append_zeroes)
{
    char *expect = "abc\0\0";
    char dst[6];

    for (int i = 0; i < 6; i++)
        dst[i] = 1;
    my_cstrncpy(dst, "abc", 6);
    for (int i = 0; i < 6; i++)
        cr_assert_eq(dst[i], expect[i]);
}

Test(my_cstrrev, reverse_string)
{
    char *str = strdup("Hello World!");

    cr_assert_str_eq(my_cstrrev(str), "!dlroW olleH");
}

Test(my_cstrstr, find_substring)
{
    char *str = "abcdef";
    char *expected = strstr(str, "cd");
    char *got = my_cstrstr(str, "cd");

    cr_assert_eq(got, expected);
}

Test(my_cstrstr, return_null_when_not_found)
{
    char *str = "abcdef";
    char *expected = strstr(str, "Hello!");
    char *got = my_cstrstr(str, "Hello!");

    cr_assert_eq(got, expected);
}
