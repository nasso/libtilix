/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** Parsing tests
*/

#include <criterion/criterion.h>
#include "my/my.h"
#include "jzon/jzon.h"
#include "jzon/parser.h"

static const f64_t EPSILON = 0.00001;

static const char *SAMPLE_JSON =
    "{"
    "   \"foo\": \"bar\","
    "   \"bar\": \"foo\","
    "   \"hello\": 58,"
    "   \"some_obj\": {"
    "       \"inner\": \"value\","
    "       \"inner_obj\": { \"nice\": 69 },"
    "       \"arr\": [420, 69, 621],"
    "       \"nothing\": null"
    "   }"
    "}";

Test(parser, sample_json)
{
    jzon_t jz = jzon_from(SAMPLE_JSON);
    jzon_t some_obj = NULL;

    cr_assert_not_null(jz);
    cr_assert_str_eq(jzon_str(jzon_getk(jz, "foo")), "bar");
    cr_assert_str_eq(jzon_str(jzon_getk(jz, "bar")), "foo");
    cr_assert_float_eq(jzon_num(jzon_getk(jz, "hello")), 58, EPSILON);
    some_obj = jzon_getk(jz, "some_obj");
    cr_assert_str_eq(jzon_str(jzon_getk(some_obj, "inner")), "value");
    cr_assert_float_eq(
        jzon_num(jzon_getk(jzon_getk(some_obj, "inner_obj"), "nice")), 69,
        EPSILON);
    cr_assert_eq(jzon_len(jzon_getk(some_obj, "arr")), 3);
    cr_assert_float_eq(jzon_num(jzon_geti(jzon_getk(some_obj, "arr"), 0)), 420,
        EPSILON);
    cr_assert_float_eq(jzon_num(jzon_geti(jzon_getk(some_obj, "arr"), 1)), 69,
        EPSILON);
    cr_assert_float_eq(jzon_num(jzon_geti(jzon_getk(some_obj, "arr"), 2)), 621,
        EPSILON);
    cr_assert(jzon_is_null(jzon_getk(some_obj, "nothing")));
}

Test(parser, parse_null)
{
    jzon_t jz = jzon_from("null");

    cr_assert_not_null(jz);
    cr_assert(jzon_is_null(jz));
}

Test(parser, parse_true)
{
    jzon_t jz = jzon_from("true");

    cr_assert_not_null(jz);
    cr_assert_eq(jz->v->type, JZ_BOOL);
    cr_assert_eq(jzon_bool(jz), true);
}

Test(parser, parse_false)
{
    jzon_t jz = jzon_from("false");

    cr_assert_not_null(jz);
    cr_assert_eq(jz->v->type, JZ_BOOL);
    cr_assert_eq(jzon_bool(jz), false);
}

Test(parser, parse_integer_num)
{
    cr_assert_float_eq(jzon_num(jzon_from("0")), 0, EPSILON);
    cr_assert_float_eq(jzon_num(jzon_from("1")), 1, EPSILON);
    cr_assert_float_eq(jzon_num(jzon_from("59")), 59, EPSILON);
    cr_assert_float_eq(jzon_num(jzon_from("-63")), -63, EPSILON);
}

Test(parser, parse_floating_point_num)
{
    cr_assert_float_eq(jzon_num(jzon_from("0.0")), 0, EPSILON);
    cr_assert_float_eq(jzon_num(jzon_from("\n\n0.0000")), 0, EPSILON);
    cr_assert_float_eq(jzon_num(jzon_from("1.002")), 1.002, EPSILON);
    cr_assert_float_eq(jzon_num(jzon_from(" 59.95")), 59.95, EPSILON);
    cr_assert_float_eq(jzon_num(jzon_from("-63.936")), -63.936, EPSILON);
    cr_assert_float_eq(jzon_num(jzon_from("-0.420  ")), -0.420, EPSILON);
}

Test(parser, parse_exp_num)
{
    cr_assert_float_eq(jzon_num(jzon_from(" 0e98\t")), 0e98, EPSILON);
    cr_assert_float_eq(jzon_num(jzon_from("  9e2 ")), 9e2, EPSILON);
    cr_assert_float_eq(jzon_num(jzon_from("-7E3")), -7E3, EPSILON);
    cr_assert_float_eq(jzon_num(jzon_from("-37.13e+10")), -37.13e+10, EPSILON);
    cr_assert_float_eq(jzon_num(jzon_from("-37.13e-2")), -37.13e-2, EPSILON);
}

Test(parser, parse_string)
{
    cr_assert_str_eq(jzon_str(jzon_from("\"\"")), "");
    cr_assert_str_eq(jzon_str(jzon_from(" \t  \"hey\" \t")), "hey");
    cr_assert_str_eq(jzon_str(jzon_from("\"hgeils\\n\\tbg\"")), "hgeils\n\tbg");
    cr_assert_str_eq(jzon_str(jzon_from("\"\\\" \\/ ht\"")), "\" / ht");
}

Test(parser, parse_empty_array)
{
    jzon_t jz = jzon_from("  [] ");

    cr_assert_not_null(jz);
    cr_assert_eq(jzon_len(jz), 0);
    jzon_drop(jz);
}

Test(parser, parse_empty_array_ws)
{
    jzon_t jz = jzon_from("  [  ] ");

    cr_assert_not_null(jz);
    cr_assert_eq(jzon_len(jz), 0);
    jzon_drop(jz);
}

Test(parser, parse_array)
{
    jzon_t jz = jzon_from("  [ \" he\" , 52, false,null,true,[1, 2,3] ] ");

    cr_assert_not_null(jz);
    cr_assert_eq(jzon_len(jz), 6);
    cr_assert_str_eq(jzon_geti_str(jz, 0), " he");
    cr_assert_float_eq(jzon_geti_num(jz, 1), 52, EPSILON);
    cr_assert_eq(jzon_geti_bool(jz, 2), false);
    cr_assert(jzon_geti_is_null(jz, 3));
    cr_assert_eq(jzon_geti_bool(jz, 4), true);
    cr_assert_eq(jzon_geti_len(jz, 5), 3);
    cr_assert_float_eq(jzon_getq_num(jz, "[5][0]"), 1, EPSILON);
    cr_assert_float_eq(jzon_getq_num(jz, "[5][1]"), 2, EPSILON);
    cr_assert_float_eq(jzon_getq_num(jz, "[5][2]"), 3, EPSILON);
}

Test(parser, parse_empty_object)
{
    jzon_t jz = jzon_from("  {  } ");

    cr_assert_not_null(jz);
    cr_assert_eq(jzon_len(jz), 0);
    jzon_drop(jz);
}

Test(parser, parse_object)
{
    jzon_t jz = jzon_from(" { \"foo\"\t:\"bar\" ,  \"bar\"  : false } ");

    cr_assert_not_null(jz);
    cr_assert_eq(jzon_len(jz), 2);
    cr_assert_str_eq(jzon_getk_str(jz, "foo"), "bar");
    cr_assert_eq(jzon_getk_bool(jz, "bar"), false);
    jzon_drop(jz);
}

Test(parser, parse_object_recurse)
{
    jzon_t jz = jzon_from(" { \"foo\"\t:\"bar\" , \"bar\"  : {\"ha\":\"hi\"}}");

    cr_assert_not_null(jz);
    cr_assert_eq(jzon_len(jz), 2);
    cr_assert_str_eq(jzon_getk_str(jz, "foo"), "bar");
    cr_assert_str_eq(jzon_getq_str(jz, ".bar.ha"), "hi");
    jzon_drop(jz);
}
