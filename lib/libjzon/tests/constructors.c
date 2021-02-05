/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** Unit tests
*/

#include <criterion/criterion.h>
#include "jzon/jzon.h"

Test(constructors, create_str)
{
    jzon_t jz = jzon_create_str("Hello!");

    cr_assert_not_null(jz);
    cr_assert_eq(jz->v->type, JZ_STR);
    cr_assert_str_eq(jz->v->u.str, "Hello!");
    jzon_drop(jz);
}

Test(constructors, create_num)
{
    jzon_t jz = jzon_create_num(420.69);

    cr_assert_not_null(jz);
    cr_assert_eq(jz->v->type, JZ_NUM);
    cr_assert_eq(jz->v->u.num, 420.69);
    jzon_drop(jz);
}

Test(constructors, create_obj)
{
    jzon_t jz = jzon_create_obj();

    cr_assert_not_null(jz);
    cr_assert_eq(jz->v->type, JZ_OBJ);
    cr_assert_not_null(jz->v->u.obj);
    cr_assert_eq(jz->v->u.obj->size, 0);
    jzon_drop(jz);
}

Test(constructors, create_arr)
{
    jzon_t jz = jzon_create_arr();

    cr_assert_not_null(jz);
    cr_assert_eq(jz->v->type, JZ_ARR);
    cr_assert_not_null(jz->v->u.arr);
    cr_assert_eq(jz->v->u.arr->len, 0);
    jzon_drop(jz);
}

Test(constructors, create_bool)
{
    jzon_t jz = jzon_create_bool(true);

    cr_assert_not_null(jz);
    cr_assert_eq(jz->v->type, JZ_BOOL);
    cr_assert_eq(jz->v->u.bool_val, true);
    jzon_drop(jz);
}

Test(constructors, create_null)
{
    jzon_t jz = jzon_create_null();

    cr_assert_not_null(jz);
    cr_assert_eq(jz->v->type, JZ_NULL);
    jzon_drop(jz);
}
