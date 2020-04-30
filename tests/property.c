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

Test(property, parse_list)
{
    tl_properties_t props = {0};

    cr_assert_not(jzon_deser_cstr(EXAMPLE, &TL_PROPERTIES_TYPE_DESC, NULL,
        &props));
    cr_assert_eq(props.len, 6);
}

Test(property, string)
{
    tl_properties_t props = {0};

    jzon_deser_cstr(EXAMPLE, &TL_PROPERTIES_TYPE_DESC, NULL, &props);
    cr_assert_eq(props.data[0].type, TL_STRING);
    cr_assert_str_eq(props.data[0].u.str, "baa");
    cr_assert_str_eq(tl_properties_get_str(&props, "v_str"), "baa");
}

Test(property, int)
{
    tl_properties_t props = {0};

    jzon_deser_cstr(EXAMPLE, &TL_PROPERTIES_TYPE_DESC, NULL, &props);
    cr_assert_eq(props.data[1].type, TL_INT);
    cr_assert_eq(props.data[1].u.i, 69);
    cr_assert_eq(tl_properties_get_i64(&props, "v_int"), 69);
}

Test(property, float)
{
    tl_properties_t props = {0};

    jzon_deser_cstr(EXAMPLE, &TL_PROPERTIES_TYPE_DESC, NULL, &props);
    cr_assert_eq(props.data[2].type, TL_FLOAT);
    cr_assert_float_eq(props.data[2].u.f, 62.1, EPSILON);
    cr_assert_float_eq(tl_properties_get_f64(&props, "v_flt"), 62.1, 0.001);
}

Test(property, bool)
{
    tl_properties_t props = {0};

    jzon_deser_cstr(EXAMPLE, &TL_PROPERTIES_TYPE_DESC, NULL, &props);
    cr_assert_eq(props.data[3].type, TL_BOOL);
    cr_assert_eq(props.data[3].u.color, true);
    cr_assert(tl_properties_get_bool(&props, "v_bool"));
}

Test(property, color)
{
    tl_properties_t props = {0};

    jzon_deser_cstr(EXAMPLE, &TL_PROPERTIES_TYPE_DESC, NULL, &props);
    cr_assert_eq(props.data[4].type, TL_COLOR);
    cr_assert_eq(props.data[4].u.color, 0x86abcdef);
    cr_assert_eq(tl_properties_get_color(&props, "v_col"), 0x86aBcdEf);
}

Test(property, file)
{
    tl_properties_t props = {0};

    jzon_deser_cstr(EXAMPLE, &TL_PROPERTIES_TYPE_DESC, NULL, &props);
    cr_assert_eq(props.data[5].type, TL_FILE);
    cr_assert_str_eq(props.data[5].u.file, "baa.json");
    cr_assert_str_eq(tl_properties_get_file(&props, "v_file"), "baa.json");
}
