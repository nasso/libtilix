/*
** EPITECH PROJECT, 2020
** libtilix
** File description:
** Color parser tests
*/

#include <criterion/criterion.h>
#include "my/my.h"
#include "tilix/common_deser.h"

Test(color, parse_rgb)
{
    u32_t val = 0;

    cr_assert_not(jzon_deser_cstr("\"#abcdef\"", &TL_COLOR_STR_TYPE_DESC, NULL,
        &val));
    cr_assert_eq(val, 0xFFABCDEF);
}

Test(color, parse_argb)
{
    u32_t val = 0;

    cr_assert_not(jzon_deser_cstr("\"#94abcdef\"", &TL_COLOR_STR_TYPE_DESC,
        NULL, &val));
    cr_assert_eq(val, 0x94ABCDEF);
}
