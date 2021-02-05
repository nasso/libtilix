/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** cstr reader tests
*/

#include <criterion/criterion.h>
#include "my/my.h"
#include "my/io.h"

Test(cstrreader, getchar_small_buffer)
{
    bufreader_t *br = cstrreader_new("Hello World!", 8);

    cr_assert_not_null(br);
    cr_assert_eq(bufreader_getchar(br), 'H');
    cr_assert_eq(bufreader_getchar(br), 'e');
    cr_assert_eq(bufreader_getchar(br), 'l');
    cr_assert_eq(bufreader_getchar(br), 'l');
    cr_assert_not(br->ended);
    cr_assert_eq(bufreader_getchar(br), 'o');
    cr_assert_eq(bufreader_getchar(br), ' ');
    cr_assert_eq(bufreader_getchar(br), 'W');
    cr_assert_eq(bufreader_getchar(br), 'o');
    cr_assert_eq(bufreader_getchar(br), 'r');
    cr_assert_eq(bufreader_getchar(br), 'l');
    cr_assert_eq(bufreader_getchar(br), 'd');
    cr_assert_eq(bufreader_getchar(br), '!');
    cr_assert_not(br->ended);
    cr_assert_eq(bufreader_getchar(br), '\0');
    cr_assert(br->ended);
    bufreader_free(br);
}

Test(cstrreader, getchar_big_buffer)
{
    bufreader_t *br = cstrreader_new("Hello World!", 256);

    cr_assert_not_null(br);
    cr_assert_eq(bufreader_getchar(br), 'H');
    cr_assert_eq(bufreader_getchar(br), 'e');
    cr_assert_eq(bufreader_getchar(br), 'l');
    cr_assert_eq(bufreader_getchar(br), 'l');
    cr_assert_not(br->ended);
    cr_assert_eq(bufreader_getchar(br), 'o');
    cr_assert_eq(bufreader_getchar(br), ' ');
    cr_assert_eq(bufreader_getchar(br), 'W');
    cr_assert_eq(bufreader_getchar(br), 'o');
    cr_assert_eq(bufreader_getchar(br), 'r');
    cr_assert_eq(bufreader_getchar(br), 'l');
    cr_assert_eq(bufreader_getchar(br), 'd');
    cr_assert_eq(bufreader_getchar(br), '!');
    cr_assert_not(br->ended);
    cr_assert_eq(bufreader_getchar(br), '\0');
    cr_assert(br->ended);
    bufreader_free(br);
}

Test(cstrreader, read_line)
{
    bufreader_t *br = cstrreader_new("Hello\nWorld!\nhaha", 8);

    cr_assert_str_eq(bufreader_read_line(br), "Hello\n");
    cr_assert_str_eq(bufreader_read_line(br), "World!\n");
    cr_assert_str_eq(bufreader_read_line(br), "haha");
    cr_assert_null(bufreader_read_line(br));
    bufreader_free(br);
}

Test(cstrreader, read_last_line)
{
    bufreader_t *br = cstrreader_new("Hello\nWorld!\n", 8);

    cr_assert_str_eq(bufreader_read_line(br), "Hello\n");
    cr_assert_str_eq(bufreader_read_line(br), "World!\n");
    cr_assert_null(bufreader_read_line(br));
    bufreader_free(br);
}

Test(cstrreader, read_all)
{
    bufreader_t *br = cstrreader_new("Hello\nWorld!\nhaha", 8);

    cr_assert_str_eq(bufreader_read_all(br), "Hello\nWorld!\nhaha");
    cr_assert_null(bufreader_read_all(br));
    bufreader_free(br);
}
