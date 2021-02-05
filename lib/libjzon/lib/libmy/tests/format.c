/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** tests - formatting
*/

#include <criterion/criterion.h>
#include "my/my.h"
#include "my/fmt.h"

Test(my_format, invalid_specifier)
{
    cr_assert_str_eq(my_format( "<%k>"),  "<%k>");
    cr_assert_str_eq(my_format( "<%31.5k>"),  "<%31.5k>");
    cr_assert_str_eq(my_format( "<%31.5k> %d", 42),  "<%31.5k> 42");
}

Test(my_format, simple_no_args)
{
    char *str = my_format("Hello World!");

    cr_assert_str_eq(str, "Hello World!");
}

Test(my_format, multiple)
{
    char *str = my_format("%s %s!", "Hello", "World");

    cr_assert_str_eq(str, "Hello World!");
}

Test(my_format, strings)
{
    cr_assert_str_eq(my_format("%s World!", "Hello"), "Hello World!");
    cr_assert_str_eq(my_format("%.4s World!", "Hello"), "Hell World!");
    cr_assert_str_eq(my_format("%10.5s", "hello world"), "     hello");
    cr_assert_str_eq(my_format("%8s", "uwu"), "     uwu");
    cr_assert_str_eq(my_format("%-8s", "uwu"), "uwu     ");
    cr_assert_str_eq(my_format("%5zs", my_sstr("uwu")), "  uwu");
}

Test(my_format, string_non_printable)
{
    cr_assert_str_eq(my_format("%S", "uwu"), "uwu");
    cr_assert_str_eq(my_format("%S", "uwu\012owo"), "uwu\\012owo");
    cr_assert_str_eq(my_format("%.3S", "uwu\012owo"), "uwu");
    cr_assert_str_eq(my_format("%.4S", "uwu\012owo"), "uwu\\012");
    cr_assert_str_eq(my_format("%.5S", "uwu\012owo"), "uwu\\012o");
    cr_assert_str_eq(my_format("%4.5S", "uwu\012owo"), "uwu\\012o");
    cr_assert_str_eq(my_format("%10.5S", "uwu\012owo"), "  uwu\\012o");
}

Test(my_format, decimal_basics)
{
    cr_assert_str_eq(my_format("%i",  42), "42");
    cr_assert_str_eq(my_format("%d",  42), "42");
    cr_assert_str_eq(my_format("%d", -42), "-42");
}

Test(my_format, decimal_sign)
{
    cr_assert_str_eq(my_format("%+d",  42), "+42");
    cr_assert_str_eq(my_format("%+d", -42), "-42");
    cr_assert_str_eq(my_format("% d",  42), " 42");
    cr_assert_str_eq(my_format("% d", -42), "-42");
}

Test(my_format, decimal_field_width)
{
    cr_assert_str_eq(my_format(  "%5d", 42), "   42");
    cr_assert_str_eq(my_format( "%05d", 42), "00042");
    cr_assert_str_eq(my_format( "%-5d", 42), "42   ");
    cr_assert_str_eq(my_format( "%-5d", 42), "42   ");
    cr_assert_str_eq(my_format("%+05d", 42), "+0042");
    cr_assert_str_eq(my_format("%+-5d", 42), "+42  ");
    cr_assert_str_eq(my_format("% -5d", 42), " 42  ");
}

Test(my_format, decimal_precision)
{
    cr_assert_str_eq(my_format( "%.d",  0),   "");
    cr_assert_str_eq(my_format( "%.d", 42), "42");
    cr_assert_str_eq(my_format("%.0d", 42), "42");
    cr_assert_str_eq(my_format("%.5d", 42), "00042");
    cr_assert_str_eq(my_format("%.*d",  0, 42), "42");
    cr_assert_str_eq(my_format("%.*d", -5, 42), "42");
    cr_assert_str_eq(my_format("%.*d",  5, 42), "00042");
    cr_assert_str_eq(my_format("%08.4d", 42), "    0042");
}

Test(my_format, decimal_length_mod)
{
    cr_assert_str_eq(my_format("%hhd", 127), "127");
    cr_assert_str_eq(my_format("%hhd", 128), "-128");
    cr_assert_str_eq(my_format("%hd", 15623), "15623");
    cr_assert_str_eq(my_format("%ld", 2147483648L), "2147483648");
}

Test(my_format, unsigned_bases)
{
    cr_assert_str_eq(my_format("%b", 0xE621), "1110011000100001");
    cr_assert_str_eq(my_format("%o", 0xE621), "163041");
    cr_assert_str_eq(my_format("%u", 0xE621), "58913");
    cr_assert_str_eq(my_format("%x", 0xE621), "e621");
    cr_assert_str_eq(my_format("%X", 0xE621), "E621");
}

Test(my_format, unsigned_bases_options)
{
    cr_assert_str_eq(my_format("%4b", 0xE621), "1110011000100001");
    cr_assert_str_eq(my_format("%8o", 0xE621), "  163041");
    cr_assert_str_eq(my_format("%08o", 0xE621), "00163041");
    cr_assert_str_eq(my_format("%.8o", 0xE621), "00163041");
    cr_assert_str_eq(my_format("%10.8u", 0xE621), "  00058913");
    cr_assert_str_eq(my_format("%06x", 0xE621), "00e621");
    cr_assert_str_eq(my_format("%+ X", 0xE621), "E621");
}

Test(my_format, unsigned_bases_alt_forms)
{
    cr_assert_str_eq(my_format("%#b", 0xE621), "1110011000100001");
    cr_assert_str_eq(my_format("%#o", 0xE621), "0163041");
    cr_assert_str_eq(my_format("%#o", 0x0), "0");
    cr_assert_str_eq(my_format("%#.4o", 0x0), "0000");
    cr_assert_str_eq(my_format("%#04o", 0x0), "0000");
    cr_assert_str_eq(my_format("%#04o", 0xE621), "0163041");
    cr_assert_str_eq(my_format("%#.4o", 0xE621), "0163041");
    cr_assert_str_eq(my_format("%#08o", 0xE621), "00163041");
    cr_assert_str_eq(my_format("%#.8o", 0xE621), "00163041");
    cr_assert_str_eq(my_format("%#x", 0xE621), "0xe621");
    cr_assert_str_eq(my_format("%#.6x", 0xE621), "0x00e621");
    cr_assert_str_eq(my_format("%#X", 0xE621), "0XE621");
}

Test(my_format, pointer)
{
    cr_assert_str_eq(my_format("%p", 0xE621), "0xe621");
    cr_assert_str_eq(my_format("%#-16.8jx;", 0xE621), "0x0000e621      ;");
}

Test(my_format, percent)
{
    cr_assert_str_eq(my_format("%%"), "%");
    cr_assert_str_eq(my_format("%%%%"), "%%");
}
