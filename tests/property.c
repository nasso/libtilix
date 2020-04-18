/*
** EPITECH PROJECT, 2020
** libtilix
** File description:
** Property parser tests
*/

#include <criterion/criterion.h>
#include "my/my.h"
#include "tilix/property.h"

static const f64_t EPSILON = 0.0001;
static const char *EXAMPLE =
    "["
    "   { \"name\": \"v_str\", \"type\": \"string\", \"value\": \"baa\" },"
    "   { \"name\": \"v_int\", \"type\": \"int\", \"value\": 69 },"
    "   { \"name\": \"v_flt\", \"type\": \"float\", \"value\": 62.1 },"
    "   { \"name\": \"v_bool\", \"type\": \"bool\", \"value\": true },"
    "   { \"name\": \"v_col\", \"type\": \"color\", \"value\": \"#86aBcdEf\" },"
    "   { \"name\": \"v_file\", \"type\": \"file\", \"value\": \"baa.json\" }"
    "]";

struct properties {
    tl_property_t *data;
    usize_t len;
};

Test(property, parse_list)
{
    struct properties props;

    cr_assert_not(jzon_deser_cstr(EXAMPLE, &TL_PROPERTIES_TYPE_DESC, NULL,
        &props));
    cr_assert_eq(props.len, 6);
}

Test(property, string)
{
    struct properties props;

    jzon_deser_cstr(EXAMPLE, &TL_PROPERTIES_TYPE_DESC, NULL, &props);
    cr_assert_eq(props.data[0].type, TL_STRING);
    cr_assert_str_eq(props.data[0].u.str, "baa");
}

Test(property, int)
{
    struct properties props;

    jzon_deser_cstr(EXAMPLE, &TL_PROPERTIES_TYPE_DESC, NULL, &props);
    cr_assert_eq(props.data[1].type, TL_INT);
    cr_assert_eq(props.data[1].u.i, 69);
}

Test(property, float)
{
    struct properties props;

    jzon_deser_cstr(EXAMPLE, &TL_PROPERTIES_TYPE_DESC, NULL, &props);
    cr_assert_eq(props.data[2].type, TL_FLOAT);
    cr_assert_float_eq(props.data[2].u.f, 62.1, EPSILON);
}

Test(property, bool)
{
    struct properties props;

    jzon_deser_cstr(EXAMPLE, &TL_PROPERTIES_TYPE_DESC, NULL, &props);
    cr_assert_eq(props.data[3].type, TL_BOOL);
    cr_assert_eq(props.data[3].u.color, true);
}

Test(property, color)
{
    struct properties props;

    jzon_deser_cstr(EXAMPLE, &TL_PROPERTIES_TYPE_DESC, NULL, &props);
    cr_assert_eq(props.data[4].type, TL_COLOR);
    cr_assert_eq(props.data[4].u.color, 0x86abcdef);
}

Test(property, file)
{
    struct properties props;

    jzon_deser_cstr(EXAMPLE, &TL_PROPERTIES_TYPE_DESC, NULL, &props);
    cr_assert_eq(props.data[5].type, TL_FILE);
    cr_assert_str_eq(props.data[5].u.file, "baa.json");
}
